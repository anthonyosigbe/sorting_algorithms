#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order,
 * using the Insertion Sort algorithm.
 * @list: A pointer to a pointer to the head of the list
 *
 * REturn: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		sorted = current->prev;
		while (sorted && current->n < sorted->n)
		{
			temp = current->next;
			if (sorted->prev)
				sorted->prev->next = current;
			else
				*list = current;

			if (temp)
				temp->prev = sorted;

			current->prev = sorted->prev;
			sorted->next = temp;
			current->next = sorted;
			sorted->prev = current;

			print_list(*list);
			sorted = current->prev;
		}
		current = current->next;
	}
}
