#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: Array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = size;
	int _flag;
	size_t i, j;
	int _temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < n - 1; i++)
	{
		_flag = 0;
		for (j = 0; j < n - (i + 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				_temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = _temp;
				print_array(array, n);
				_flag = 1;
			}
		}
		if (_flag == 0)
			break;
	}
}
