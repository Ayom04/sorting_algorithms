#include "sort.h"

/**
 * _swap_l - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void _swap_l(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort - Sort an array of integers in ascending order
 * using the bubble sort
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size;
	int _flag;
	size_t i, j;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < n - 1; i++)
	{
		_flag = 0;
		for (j = 0; j < n - (i + 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, n);
				_flag = 1;
			}
		}
		if (_flag == 0)
			break;

	}
}
