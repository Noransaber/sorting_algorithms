#include "sort.h"
#include <stddef.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: List of array to be sorted
 * @size: Size of the array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int gap, x, swapped;
	size_t i, j;

	if (size <= 1)
		return;

	for (gap = size / 2; gap >= 1; gap = gap / 2)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			swapped = 0;
			if (array[i] > array[j])
				swap_sh(array, i, j, &swapped);
			for (x = i; x >= gap && swapped == 1; x--)
			{
				swapped = 0;
				if (array[x - gap] > array[x])
					swap_sh(array, (x - gap), x, &swapped);
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_sh - Swaps elements of an array of two given indexes
 * @arr: Array to swap elements from
 * @x: index 1
 * @y: index 2
 * @swapped: Flag to control backward sorting in the shell sort function
 *  Return: void
 */

void swap_sh(int *arr, int x, int y, int *swapped)
{
	int tmp = arr[x];

	arr[x] = arr[y];
	arr[y] = tmp;
	*swapped = 1;
}
