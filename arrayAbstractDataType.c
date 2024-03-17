#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/**** the array abstract data type ****/
struct arrayType
{
	int32_t data[50];
	int32_t capacity;    //capacity of the array is capped at 50
	int32_t length; 	 //lenght of array the user wants to initialise. always <= to capacity
};

typedef struct arrayType array;

/**** functions prototypes ****/
void append(array *arr, uint32_t element);
void insert(array *arr, uint32_t idx, uint32_t element);
int32_t deleteElement(array *arr, uint32_t idx);
void reverse(array *arr);
void printArray(array *arr);


int main(int argc, char *argv[])
{
	array signal = {
	  {10,20,30,11,12,13,14}, 50, 7
	};
	
	printf("The original array is: \n\r");
	printArray(&signal);
	
	append(&signal, 3000);
	
	printf("The array after append is: \n\r");
	printArray(&signal);
	
	insert(&signal, 2, 4000);
	printf("The array after insert at idx 2 is: \n\r");
	printArray(&signal);
	
	insert(&signal, 8, 600);
	printf("The array after insert at idx 8 is: \n\r");
	printArray(&signal);
	
	int32_t lostElement = deleteElement(&signal, 2);
	printf("The array after deleting idx 2 is: \n\r");
	printArray(&signal);
	printf("the deleted element is %d\n", lostElement);
	
	printf("\n");
	reverse(&signal);
	printf("The array after being reversed is: \n\r");
	printArray(&signal);

		
	

	return 0;
}

/* types of insertion:
1 - at the beginning of the list
2 - in a random position of the list (insertion)
3 - in the end of the list (often called append) 
*/
void append(array *arr, uint32_t element)
{
	/* check if the array is in its full capacity */
	if(arr->length < arr->capacity)
	{
		arr->data[arr->length++] = element;
	}
	else
	{
		printf("The array is full\n");
	}
}

void insert(array *arr, uint32_t idx, uint32_t element)
{
	if(idx <= arr->length)
	{
	  //shift the current element to create space
	  for(int i = arr->length; i > idx; i--)
	  {
	  	arr->data[i] = arr->data[i-1];
	  }
	  arr->data[idx] = element;
	  arr->length++;
	}
}

void printArray(array *arr)
{
	for(int i = 0; i < arr->length; i++)
	{
		printf(" %d ", arr->data[i]);
	}
	printf("\n\n");
}

int32_t deleteElement(array *arr, uint32_t idx)
{
	int32_t element;
	
	if(idx < arr->length)
	{
	  element = arr->data[idx];
	  for(int i = idx; i < arr->length - 1; i++)
	  {
		arr->data[i] = arr->data[i+1];
	  }
	  arr->length--;
	  return element;
	}
	
	return 0;
}

void reverse(array *arr)
{
	int i, j;
	int32_t *temp;
	
	temp = (int32_t *)malloc(arr->length*sizeof(int32_t));
	
	for(i = arr->length - 1, j = 0; i >=0; i--,j++)
	{
		temp[j] = arr->data[i];
	}
	
	for(i = 0; i < arr->length; i++)
	{
		arr->data[i] = temp[i];
	}
}




