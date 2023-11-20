#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort
 *
 * @array: array to sort
 * @size: size of the array to sort
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int sorted;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		sorted = 1;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
				sorted = 0;
			}
		}
		if (sorted)
			break;
	}
}

/**
 * swap - swaps two integers
 *
 * @array: array to swap
 * @idx1: index one for fisrt integer
 * @idx2: index two for second integer
 * Return: void
 */

void swap(int *array, size_t idx1, size_t idx2)
{
	int temp;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
