#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void swap(int *array, size_t idx1, size_t idx2);
void insertion_sort_list(listint_t **list);
void swap_list(listint_t **h, listint_t *prev, listint_t *current);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
size_t lomuto_partition(int *array, int start, int end, size_t size);
void handle_quick_sort(int *array, int start, int end, size_t size);

#endif
