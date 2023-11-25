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

	if (array == NULL || size == 0)
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
