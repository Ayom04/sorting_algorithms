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
    void bubble_sort(int *array, size_t size) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        size_t i = 0;
        while (i < size - 1) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = 1;
                printf("Swapping %d and %d\n", array[i], array[i+1]);
            }
            i++;
        }
        size--;
    }
}
}
