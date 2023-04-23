#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 *insertion_sort_list - Sorts a doubly linked list of integers
 *using the insertion sort algorithm.
 *@list: Array to be sorted.
 *Return: Nothing
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
		sort_l = h->prev;
		while (sort_l != NULL && sort_l->n > temp->n)
		{
			swap(list, &sort_l, temp);
			print_list(*list);
		}
	}
}
