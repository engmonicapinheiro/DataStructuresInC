/* a copy of the implementation present in 
 * https://embedjournal.com/implementing-circular-buffer-embedded-c
 * 20/03/2024
*/


#include<stdio.h>
#include<stdint.h>

/* the data structure definition */
typedef struct
{
	uint8_t* const buffer;
	int head;
	int tail;
	const int maxlen;
} circularBuffer_t;


/* functions prototypes */
int circularBufferPush(circularBuffer_t *c, uint8_t data);
int circularBufferPop(circularBuffer_t *c, uint8_t *data);

uint8_t dataspace[32];
circularBuffer_t circularBuffer = {dataspace, 0, 0, 32};

int main(int argc, char*argv[])
{
	uint8_t outData = 0;
	uint8_t inData = 0x45;
	

	if(circularBufferPush(&circularBuffer, inData))
	{
		printf("Out of space in the circular buffer.\n");
		return -1;
	}
	
	if(circularBufferPop(&circularBuffer, &outData))
	{
		printf("the circular buffer is empty.\n");
		return -1;
	}


	printf("Push: 0x%x\n", inData);
	printf("Pop: 0x%x\n", outData);

	return 0;
}

/* push data into the circular buffer */
int circularBufferPush(circularBuffer_t *c, uint8_t data)
{
	int next;
	
	//next is where head will point to after this write
	next = c->head + 1; 
	
	if(next >= c->maxlen)
	{
		next = 0;
	}
	
	//if head + 1 == tail, the circular buffer is full
	if(next == c->tail)
	{
		return -1;
	}
	
	//load data and then move
	c->buffer[c->head] = data;
	//head to next data offset
	c->head = next;

	//a successful push
	return 0;
}

/* pop data from the circular buffer */
int circularBufferPop(circularBuffer_t *c, uint8_t *data)
{
	int next;
	
	//if head==tail, we don't have any data
	if(c->head == c->tail)
	{
		return -1;
	}
	
	//next is where tail will point to after this read
	next = c->tail + 1;
	if(next >= c->maxlen)
	{
		next = 0;
	}
	
	//read data and then move
	*data = c->buffer[c->tail];
	//tail to next offset
	c->tail = next;
	
	return 0;
}
