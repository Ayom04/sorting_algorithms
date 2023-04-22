#include "sort.h"

/**
 *selection_sort - sorts an array of integers in ascending
 *order using the Selection sort algorithm
 *@array: Array to be sorted
 *@size: Size of array
 *Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t n = size, min, i, j, temp;

	if (!array || size < 2)
		return;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, n);
		}
	}
}
