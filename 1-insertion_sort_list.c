#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascd ordr
 * @list: Double pointer to the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *temp_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp_node = current;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > temp_node->n)
		{
			if (temp_node->next != NULL)
				temp_node->next->prev = prev_node;
			prev_node->next = temp_node->next;
			temp_node->prev = prev_node->prev;
	
			if (temp_node->prev != NULL)
				temp_node->prev->next = temp_node;

			prev_node->prev = temp_node;
			temp_node->next = prev_node;

			prev_node = temp_node->prev;

			if (temp_node->prev == NULL)
				*list = temp_node;

			print_list(*list); }

		current = current->next; }
}
