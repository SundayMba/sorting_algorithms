#include "sort.h"

/**
 * handle_quick_sort - sort an array using quick sort algorithm
 *
 * @array: array to sort
 * @start: start of the array
 * @end: end of the array
 * @size: size of array
 * Return: void
 */

void handle_quick_sort(int *array, int start, int end, size_t size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = lomuto_partition(array, start, end, size);
		print_array(array, size);
		handle_quick_sort(array, start, pIndex - 1, size);
		handle_quick_sort(array, pIndex + 1, end, size);
	}
}

/**
 * quick_sort - sort an array using quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int end;

	end = (int)(size - 1);
	handle_quick_sort(array, 0, end, size);
}

/**
 * lomuto_partition - lomuto partition algorithm
 *
 * @array: array of integers
 * @start: start of the array
 * @end: end of the array
 * @size: size of array
 * Return: void
 */

size_t lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot, pIndex, temp, i;

	pivot = array[end];
	pIndex = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[pIndex];
			array[pIndex] = array[i];
			array[i] = temp;
			pIndex++;
			print_array(array, size);
		}
	}
	array[end] = array[pIndex];
	array[pIndex] = pivot;
	return (pIndex);
}
