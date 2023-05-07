#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
  * heap_sort - sorts an array of int in ascending order
  * using the Heap sort algorithm
  * @array: array to sort
  * @size: size of array
  */
void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp, const_size = size;

	if (array == NULL || size < 2)
		return;

	while (i >= 0)
	{
		_heapify(array, i, size, size);
		i--;
	}
	i = size - 1;
	while (i >= 0)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		_heapify(array, 0, i, const_size);
		i--;
	}
}

/**
  * _heapify - To heapify a subtree
  * @array: array to heapify
  * @size: size of array
  * @i: index of array
  * @const_size: another size of array
  */
void _heapify(int *array, size_t i, size_t size, int const_size)
{
	size_t largest = i, left = i * 2 + 1, right = i * 2 + 2, temp;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, const_size);
		_heapify(array, largest, size, const_size);
	}
}
