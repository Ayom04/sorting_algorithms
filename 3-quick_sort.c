#include "sort.h"

/**
 * _swap_l - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void _swap_l(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - Order a subset of an array of integers
 * according to the lomuto partition scheme (last element as
 * pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, buttom;

	pivot = array + right;
	for (buttom = top = left; top < right; top++)
	{
		if (array[top] < *pivot)
		{
			if (buttom < top)
			{
				_swap_l(array + top, array + buttom);
				print_array(array, size);
			}
			buttom++;
		}
	}

	if (array[buttom] > *pivot)
	{
		_swap_l(array + buttom, pivot);
		print_array(array, size);
	}

	return (buttom);
}
/**
 * lomuto_sort - Implement the quicksort algorithm through
 * recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int _pivot_position;

	if (right - left > 0)
	{
		_pivot_position = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, _pivot_position - 1);
		lomuto_sort(array, size, _pivot_position + 1, right);
	}
}
/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
