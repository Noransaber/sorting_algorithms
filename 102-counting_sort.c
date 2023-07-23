#include "sort.h"

/**
 * counting_sort - a function that sorts an array of
 * integers in ascending order using the Counting sort algorithm
 * @array: List of array to be sorted
 * @size: Size of array to be sorted
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int max, i, j, *sorted, *count;

	if (size <= 1)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		max = max > array[i] ? max : array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
		if (i > 1)
			printf(", ");
		printf("%d", count[i - 1]);
		if (i == max)
			printf(", %d\n", count[i]);
	}

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}

	for (i = (size - 1); i >= 0; i--)
	{
		j = count[array[i]] - 1;
		sorted[j] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
