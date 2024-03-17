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
uint8_t arrayIsAscending(array *arr);
uint8_t arrayIsDescending(array *arr);
void sortAscend(array *arr);
void sortDescend(array *arr);
int32_t arrayMaxValue(array *arr);
int32_t arrayMinValue(array *arr);
int32_t arraySum(array *arr);
double arrayMean(array *arr);
array* merge(array *arr1, array *arr2);
void printArray(array *arr);

