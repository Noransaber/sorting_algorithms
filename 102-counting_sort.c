#include "sort.h"

/**
 * print_sort - Print count
 * @count: count
 * @max: size of count
 * Return: void
 */
void print_sort(int *count, int max)
{
	int i;

	for (i = 0; i <= max; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count[i]);
	}
	printf("\n");
}

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
		count[i] += count[i - 1];
	print_sort(count, max);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}

	for (i = (size - 1); i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
