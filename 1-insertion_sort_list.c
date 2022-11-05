#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *current, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;
	while (current)
	{
		next = current->next;
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			prev = prev->prev;

			if (prev != current->prev) /* Swap */
			{
				/* current->prev != Null as the first node is not getting sorted*/
				current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;
				current->prev = prev;
				if (!prev) /* sorted place is the head */
					current->next = *list,
					*list = current;
				else
					current->next = prev->next,
					prev->next = current;
				/* current->next != Null as the tail is always sorted when reached*/
				current->next->prev = current;
				print_list(*list);
			}
		}
		current = next;
	}
}
