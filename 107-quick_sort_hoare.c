#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
  * swap - swap two elements
  * @a: element a
  * @b: element b
  */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
  * partition - takes first element as pivot
  * @array: array of integers
  * @low: lowest index
  * @high: last index
  * @size: size
  * Return: pivot index
  */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low, j = high;

	while (1)
	{
		while (array[j] > pivot)
			j--;
		while (array[i] < pivot)
			i++;
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
			return (j);
	}
}
/**
  * quickSort - quicksort
  * @array: array of integers
  * @low: lowest index
  * @high: last index
  * @size: size
  */
void quickSort(int array[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quickSort(array, low, pi, size);
		quickSort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quicksort an array in ascending order
 * @array: array
 * @size: number of integers
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
