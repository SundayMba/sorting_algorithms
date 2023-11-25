#include "sort.h"

/**
 * counting_sort - sort an array using counting aort algorithm
 * @array: array to sort
 * @size_arr: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size_arr)
{
	int *c_arr, max, i, *arr_temp, size;

	size = (int)size_arr;
	/* get max. value in array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	c_arr = malloc(sizeof(int) * (max + 1));
	arr_temp = malloc(sizeof(int) * size);
	for (i = 0; i <= max; i++)
		c_arr[i] = 0;
	for (i = 0; i < size; i++)
		c_arr[array[i]]++;
	/* updated count array */
	for (i = 1; i <= max; i++)
		c_arr[i] = c_arr[i] + c_arr[i - 1];
	print_array(c_arr, max + 1);
	for (i = size - 1; i >= 0; i--)
		arr_temp[--c_arr[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = arr_temp[i];
	free(c_arr);
	free(arr_temp);
}
