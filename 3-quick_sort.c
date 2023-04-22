#include "sort.h"

/**
 * swap_l - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_l(int *a, int *b)
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
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, j, i;

	pivot = array + right;
	for (j = i = left; i < right; i++)
	{
		if (array[i] < *pivot)
		{
			if (j < i)
			{
				swap_l(array + i, array + j);
				print_array(array, size);
			}
			j++;
		}
	}

	if (array[j] > *pivot)
	{
		swap_l(array + j, pivot);
		print_array(array, size);
	}

	return (j);
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
	int pivot_posi;

	if (right - left > 0)
	{
		pivot_posi = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pivot_posi - 1);
		lomuto_sort(array, size, pivot_posi + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
