#include "sort.h"

/**
 * merge_sort_subarray - Sort a subarray of integers.
 * @sub_array: A subarray of an array of integers to sort.
 * @_buffer: A buffer to store the sorted subarray.
 * @top: The front index of the array.
 * @_middle: The middle index of the array.
 * @buttom: The back index of the array.
 */
void merge_sort_subarray(int *sub_array, int *_buffer, size_t top,
		size_t _middle, size_t buttom)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + top, _middle - top);

	printf("[right]: ");
	print_array(sub_array + _middle, buttom - _middle);

	for (i = top, j = _middle; i < _middle && j < buttom; k++)
		_buffer[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < _middle; i++)
		_buffer[k++] = sub_array[i];
	for (; j < buttom; j++)
		_buffer[k++] = sub_array[j];
	for (i = top, k = 0; i < buttom; i++)
		sub_array[i] = _buffer[k++];

	printf("[Done]: ");
	print_array(sub_array + top, buttom - top);
}
/**
 * merge_recursive - Implement the merge sort algorithm through recursion.
 * @sub_array: A subarray of an array of integers to sort.
 * @_buffer: A buffer to store the sorted result.
 * @top: The front index of the subarray.
 * @buttom: The back index of the subarray.
 */
void merge_recursive(int *sub_array, int *_buffer, size_t top, size_t buttom)
{
	size_t _middle;

	if (buttom - top > 1)
	{
		_middle = top + (buttom - top) / 2;
		merge_recursive(sub_array, _buffer, top, _middle);
		merge_recursive(sub_array, _buffer, _middle, buttom);
		merge_sort_subarray(sub_array, _buffer, top, _middle, buttom);
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
	int *_buffer;

	if (array == NULL || size < 2)
		return;

	_buffer = malloc(sizeof(int) * size);
	if (_buffer == NULL)
		return;

	merge_recursive(array, _buffer, 0, size);

	free(_buffer);
}
