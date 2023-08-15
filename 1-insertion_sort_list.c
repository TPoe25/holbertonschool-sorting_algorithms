#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
 * @list: Double pointer to the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			
			if (sorted != NULL)
			sorted->prev = current;
			sorted = current; }
		else
		{
			listint_t *temp = sorted;		
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			if (temp->next != NULL)
				temp->next->prev = current;

			current->next = temp->next;
			temp->next = current;
			current->prev = temp;
		}

		current = next;

		/* Print the list after each swap */
		print_list(*list);
	}
	*list = sorted;
}
