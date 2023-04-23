#include "sort.h"

/**
  * merge - merge two subarray of array
  * @array: array
  * @below: left index
  * @_middle: last index in first subarray after split
  * @above: last index of array
  */
void merge(int *array, int below, int _middle, int above)
{
	int i = below;
	int j = _middle + 1;
	int k = below;
	int *array_temp;

	array_temp = (int *)malloc(sizeof(array));
	if (array_temp == NULL)
		return;
	printf("merging...\n");
	printf("[left]: ");
	print_array(array + below, _middle - below);
	printf("[right]: ");
	print_array(array + _middle, above - _middle);
	while (i <= _middle && j <= above)
	{
		if (array[i] < array[j])
			array_temp[k++] = array[i++];
		else
			array_temp[k++] = array[j++];
	}
	while (i <= _middle)
		array_temp[k++] = array[i++];
	while (j <= above)
		array_temp[k++] = array[j++];
	for (i = below; i < k; i++)
		array[i] = array_temp[i];
	printf("[Done]: ");
	print_array(array, k);
	free(array_temp);
}
/**
 * mergeSort - recursion
 * @_arr: array
 * @below: first index
 * @above: last index
 */
void mergeSort(int _arr[], int below, int above)
{
	int _middle;

	if (below < above)
	{
		_middle = (below + above) / 2;
		mergeSort(_arr, below, _middle);
		mergeSort(_arr, _middle + 1, above);
		merge(_arr, below, _middle, above);
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
