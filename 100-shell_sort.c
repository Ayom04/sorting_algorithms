#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Array being sorted
 * @size: Size of array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int _no = (int)size;
	int _gape = 1, j, i;
	int temp;

	if (!array || size < 2)
		return;
	while (_gape <= _no / 3)
		_gape = _gape * 3 + 1;

	for (_gape = 1; _gape < (_no / 3);)
		_gape = _gape * 3 + 1;

	for (; _gape >= 1; _gape /= 3)
	{
		for (i = _gape; i < _no; i++)
		{
			j = i;
			while (j >= _gape && array[j - _gape] > array[j])
			{
				temp = array[j - _gape];
				array[j - _gape] = array[j];
				array[j] = temp;
				j -= _gape;
			}
		}
		print_array(array, size);
	}
}