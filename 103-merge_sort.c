#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
  * merge - merge two subarray of array
  * @array: array
  * @low: left index
  * @mid: last index in first subarray after split
  * @high: last index of array
  */
void merge(int *array, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	int *array_temp;

	array_temp = (int *)malloc(sizeof(array));
	if (array_temp == NULL)
		return;
	printf("merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);
	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
			array_temp[k++] = array[i++];
		else
			array_temp[k++] = array[j++];
	}
	while (i <= mid)
		array_temp[k++] = array[i++];
	while (j <= high)
		array_temp[k++] = array[j++];
	for (i = low; i < k; i++)
		array[i] = array_temp[i];
	printf("[Done]: ");
	print_array(array, k);
	free(array_temp);
}
/**
 * mergeSort - recursion
 * @arr: array
 * @low: first index
 * @high: last index
 */
void mergeSort(int arr[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
/**
  * merge_sort - merge sort
  * @array: array
  * @size: size of array
  */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	mergeSort(array, 0, size - 1);
}
