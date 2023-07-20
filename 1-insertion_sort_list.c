#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *sorted = NULL;
	listint_t *temp;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
			print_list(sorted);
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && current->n > temp->next->n)
				temp = temp->next;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
			print_list(sorted);
		}
		current = next;
	}
	*list = sorted;
}
