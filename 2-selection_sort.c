#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 *
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t min, i, j, temp;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
