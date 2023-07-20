#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *head = NULL;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (*list != NULL)
	{
		*list = (*list)->next;
		if (head == NULL || current->n < head->n)
		{
			current->next = head;
			head = current;
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				if (temp->next == NULL ||
				    current->n < temp->next->n)
				{
					current->next = temp->next;
					temp->next = current;
					break;
				}
				temp = temp->next;
			}
		}
	}
}
