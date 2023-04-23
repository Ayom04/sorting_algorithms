#include "sort.h"

/**
 * merge_sort_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @top: The front index of the array.
 * @_middle: The middle index of the array.
 * @buttom: The back index of the array.
 */
void merge_sort_subarr(int *subarr, int *buffer, size_t top, size_t _middle,
		size_t buttom)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + top, _middle - top);

	printf("[right]: ");
	print_array(subarr + _middle, buttom - _middle);

	for (i = top, j = _middle; i < _middle && j < buttom; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < _middle; i++)
		buff[k++] = subarr[i];
	for (; j < buttom; j++)
		buff[k++] = subarr[j];
	for (i = top, k = 0; i < buttom; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + top, buttom - top);
}
/**
 * merge_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @top: The front index of the subarray.
 * @buttom: The back index of the subarray.
 */
void merge_recursive(int *subarr, int *buffer, size_t top, size_t buttom)
{
	size_t mid;

	if (buttom - top > 1)
	{
		mid = top + (buttom - top) / 2;
		merge_recursive(subarr, buffer, top, mid);
		merge_recursive(subarr, buffer, mid, buttom);
		merge_sort_subarr(subarr, buffer, top, mid, buttom);
	}
}
/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
