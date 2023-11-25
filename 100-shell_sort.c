#include "sort.h"

/**
 * shell_sort - sorting algorithm that implement shell sort
 * @array: array of element to be sorted
 * @size_arr: size of the array
 * Return: void
 */

void shell_sort(int *array, size_t size_arr)
{
	int k, i, j, temp, gap;
	int size = (int)size_arr;
	int *sequence;

	if (size_arr == 0 || size_arr == 1 || sorted(array, size_arr) == 1)
		return;
	sequence = malloc(sizeof(int) * size);
	knuth_sequence(sequence, size);
	k = 0;
	gap = sequence[k];
	while (gap != 0)
	{
		if (gap <= size)
		{
			for (j = gap; j < size; j++)
			{
				for (i = j - gap; i >= 0; i = i - gap)
				{
					if (array[i + gap] < array[i])
					{
						temp = array[i];
						array[i] = array[i + gap];
						array[i + gap] = temp;
					}
					else
						break;
				}
			}
			print_array(array, size);
		}
		k++;
		gap = sequence[k];
	}
	free(sequence);
}

/**
 * knuth_sequence - calculate kunth sequence and fill up the array
 * @array: array to fill
 * @size: size of the array
 * Return: void
 */

void knuth_sequence(int *array, size_t size)
{
	int gap, i;

	gap = 0;
	for (i = size - 1; i >= 0; i--)
	{
		array[i] = gap;
		gap = 3 * gap + 1;
	}
}

/**
 * sorted - check if array has been sorted already
 * @array: array to check
 * @size: size of the array
 * Return: 1 - sorted, 0 -not sorted
 */

int sorted(int *array, size_t size)
{
	int sorted, n, i, j;

	n = (int)size;
	for (i = 0; i < n; i++)
	{
		sorted = 1;
		for (j = 0; j < n - i - 1; j++)
			if (array[j] > array[j + 1])
				sorted = 0;
		if (sorted)
			return (1);
		else
			return (0);
	}
	return (0);
}
