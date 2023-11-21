#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: pointer to a doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *first;
	int swap;

	if (!list)
		return;
	if (*list == NULL)
		return;
	if (*list && (*list)->next == NULL)
		return;
	current = (*list)->next;
	first = *list;
	while (current)
	{
		swap = 0;
		while (current != first  && (current->n < current->prev->n))
		{
			swap_list(list, current->prev, current);
			print_list(*list);
			first = *list;
			swap = 1;
		}
		if (swap == 0)
			current = current->next;
	}
}

/**
 * swap_list - swap a node in a doubly linked list
 *
 * @prev: previous node
 * @current: current node
 * @h: pointer to the head node
 * Return: void
 */

void swap_list(listint_t **h, listint_t *prev, listint_t *current)
{
	listint_t *prev_of_prev;

	prev_of_prev = prev->prev;
	prev->next = current->next;
	prev->prev = current;
	if (current->next != NULL)
		current->next->prev = prev;
	current->next = prev;
	current->prev = prev_of_prev;
	if (prev == *h)
		*h = current;
	else
		prev_of_prev->next = current;
}
