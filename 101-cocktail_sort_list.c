#include "sort.h"

/**
 * swap_nodes - Swaps two listint_t doubly linked list nodes
 *	the node is swapped with the next node
 *
 * @head: Pointer to the head of the doubly linked list
 * @node: Pointer to the first node
 */
void swap_nodes(listint_t **head, listint_t *node)
{
	listint_t *next;

	if (!node || ((!head || !*head) && !node->prev))
	{
		printf("Swap calling error\n");
		return;
	}

	next = node->next;
	if (!next)
	{
		printf("Error: Node has no next node\n");
		return;
	}

	node->next = next->next;
	next->next = node;
	next->prev = node->prev;
	node->prev = next;
	if (next->prev)
		next->prev->next = next;
	else /* The 2nd node becomes the head */
		*head = next;
	if (node->next) /* The 1st node isn't the tail */
		node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *			order using the Cocktail Shaker sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next)
		{
			if (current->n > current->next->n)
				swapped = 1,
				swap_nodes(list, current),
				print_list(*list);
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
				swapped = 1,
				swap_nodes(list, current->prev),
				print_list(*list);
			else
				current = current->prev;
		}
	}
}
