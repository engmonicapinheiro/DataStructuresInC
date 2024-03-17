#include "arrayType.h"


int main(int argc, char *argv[])
{
	array signal = {{10,20,30,11,12,13,14}, 50, 7};	
	array signal2 = {{11,21,31,11,11,13,14}, 50, 7};	
	array OrderedSignal = {{1,2,3,4,5,6,7,8,9,10}, 50, 10};
	
	
	/** the basic operations **/
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


	/** sorting the array **/
	uint8_t ascendingFlag = arrayIsAscending(&OrderedSignal);
	uint8_t descendingFlag = arrayIsDescending(&OrderedSignal);	
	printf("Is the array ascending? %d\n\r", ascendingFlag);
	printf("Is the array descending? %d\n\r", descendingFlag);
	
	sortAscend(&signal);
	printf("The array after being sorted in ascending order is: \n\r");
	printArray(&signal);
	
	sortDescend(&signal);
		printf("The array after being sorted in descending order is: \n\r");
	printArray(&signal);
	
	/** printing the statistics of the array **/
	int32_t maxValue = arrayMaxValue(&signal);
    printf("The maximum value of the array is: %d\n\r", maxValue);
	
	int32_t minValue = arrayMinValue(&signal);
	printf("The minimum value of the array is: %d\n\r", minValue);
	
	int32_t sum = arraySum(&signal);
	printf("The sum of the elements of the array is: %d\n\r", sum);
	
	double mean = arrayMean(&signal);
	printf("The mean of the elements of the array is: %f\n\r", mean);

	printf("\n");

	/** merging the two arrays **/
	array *fullSignal = merge(&signal, &signal2);
	
	printf("The merged array is: \n\r");
	printArray(fullSignal);


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

uint8_t arrayIsAscending(array *arr)
{
	for(int i = 0; i < arr->length-1; i++)
	{
		if(arr->data[i] > arr->data[i+1])
		{
			return 0;
		}
	}
	return 1;
}

uint8_t arrayIsDescending(array *arr)
{
	for(int i = 0; i < arr->length; i++)
	{
		if(arr->data[i] < arr->data[i+1])
		{
			return 0;
		}
	}
	return 1;
}

void sortAscend(array *arr)
{
	int32_t i, j, nTemp;
	
	for(i = 1; i < arr->length; i++)
	{
	  nTemp = arr->data[i];
	  j = i;
	  while(j > 0 && nTemp < arr->data[j-1])
	  {
	  	arr->data[j] = arr->data[j-1];
	  	j--;
	  }
	  arr->data[j] = nTemp;
	}
}

void sortDescend(array *arr)
{
	int32_t i, j, nTemp;
	
	for(i = 1; i < arr->length; i++)
	{
		nTemp = arr->data[i];
		j = i;
		while(j > 0 && nTemp > arr->data[j-1])
		{
			arr->data[j] = arr->data[j-1];
			--j;
		}
		arr->data[j] = nTemp;
	}
}

int32_t arrayMaxValue(array *arr)
{
	int32_t max = arr->data[0];
	
	for(int i = 0; i < arr->length; i++)
	{
		if(arr->data[i] > max)
		{
			max = arr->data[i];
		}
	}
	return max;
}

int32_t arrayMinValue(array *arr)
{
	int32_t min = arr->data[0];
	
	for(int i = 0; i < arr->length; i++)
	{
		if(arr->data[i] < min)
		{
			min = arr->data[i];
		}
	}
	return min;
}

int32_t arraySum(array *arr)
{
	int32_t sum = 0;
	
	for(int i = 0; i < arr->length; i++)
	{
		sum += arr->data[i];
	}
	
	return sum;
}

double arrayMean(array *arr)
{
	double mean = 0.0;
	int32_t sum = arraySum(arr);
	
	mean = ((double)sum/arr->length);
	
	return mean;
}

array* merge(array *arr1, array *arr2)
{
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t k = 0;
	
	//dinamically create an array
	array *destinationArray = (array *)malloc(sizeof(array));
	
	while(i < arr1->length && j < arr2->length)
	{
		if(arr1->data[i] < arr2->data[j])
		{
			destinationArray->data[k++] = arr1->data[i++];
		}
		else
		{
			destinationArray->data[k++] = arr2->data[j++];
		}
	}
	
	for(; i < arr1->length; i++)
	{
		destinationArray->data[k++] = arr1->data[i];
	}
	
	for(; j < arr2->length; j++)
	{
		destinationArray->data[k++] = arr2->data[j];
	}
	
	destinationArray->length = arr1->length + arr2->length;
	
	return destinationArray;
}
