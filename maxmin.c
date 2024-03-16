#include<stdio.h>

#define N 10

void MaxMin(int array[], int size, int *max, int*min);


int main(int argc, char* argv[])
{
	int data[N];
	int big;
	int small;
	
	printf("Enter %d numbers: ", N);
	
	for(int i = 0; i < N; i++)
	{
	  scanf("%d", &data[i]);
	}
	
	MaxMin(data, N, &big, &small);
	
	printf("the biggest number is %d\n", big);
	printf("the smallest number is %d\n", small);
	
	return 0;
}


void MaxMin(int array[], int size, int *max, int*min)
{
	*max = *min = *array;
	//which is the same as *max = *min = array[0];
	
	for(int i = 0; i < size; i++)
	{
		if(array[i] > *max)
		{
			*max = array[i];
		}
		else if(array[i] < *min)
		{
			*min = array[i];
		}
	}
}
