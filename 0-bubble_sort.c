#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size){
    size_t j, len = size;
	bool bub_sort = false;

    if (array == NULL || size < 2)
		return;

    while (bub_sort == false)
	{
		bub_sort = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bub_sort = false;
			}
		}
		len--;
	}
}
