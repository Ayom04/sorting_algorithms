#include "sort.h"

/**
  * insertion_sort_list - sorts a DLL of int in ascending order
  * using the Insertion sort algorithm
  * @list: DLL to sort
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev, *temp;

	if (list == NULL)
		return;

	current = next = *list;

	while (current != NULL)
	{
		while (current->prev != NULL)
		{
			prev = current->prev;
			temp = prev;
			if (prev->n > current->n)
				swap_node(prev, current, list);
			current = temp;
		}
		current = next->next;
		next = current;
	}
}

/**
  * swap_node - swap 2 nodes in DLL
  * @prev: before node
  * @current: after node
  * @list: head of DLL
**/
void swap_node(listint_t *prev, listint_t *current, listint_t **list)
{
	listint_t *temp;

	temp = prev->prev;
	if (temp)
		temp->next = current;
	current->prev = temp;
	prev->prev = current;
	prev->next = current->next;
	current->next = prev;
	if (prev->next != NULL)
		prev->next->prev = prev;
	if (current->prev == NULL)
		*list = current;
	print_list(*list);
}
