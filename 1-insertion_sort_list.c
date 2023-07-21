#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = i->next)
	{
		j = i;
		while (j->prev != NULL && j->n < j->prev->n)
		{
			if (j->next != NULL)
				j->next->prev = j->prev;
			j->prev->next = j->next;
			j->next = j->prev;
			j->prev = j->prev->prev;
			j->next->prev = j;
			if (j->prev == NULL)
				*list = j;
			else
				j->prev->next = j;
			print_list(*list);
		}
	}
}
