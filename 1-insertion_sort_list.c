#include "sort.h"

/**
 * swap - Swap nodes
 * @h: Head pointer to the linked list
 * @sort_l: pointer to the sorted part of linked list
 * @temp: Pointer to node whise value is being compared
 * Return: Nothing
 */

void swap(listint_t **h, listint_t **sort_l, listint_t *temp)
{
	if (temp->next)
		temp->next->prev = temp->prev;
	if  (temp->prev)
		temp->prev->next = temp->next;

	if ((*sort_l)->prev)
		(*sort_l)->prev->next = temp;
	else
		*h = temp;
	temp->prev = (*sort_l)->prev;
	(*sort_l)->prev = temp;
	temp->next = *sort_l;
	*sort_l = temp->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: Array to be sorted.
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sort_l, *h = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (h->prev)
		h = h->prev;

	for (h = h->next; h != NULL; h = h->next)
	{
		temp = h;
		sort_l = h->prev

		while (sort_l != NULL && sort_l->n > temp->n)
		{
			swap(list, &sort_l, temp);
			print_list(*list);
		}
	}
}
