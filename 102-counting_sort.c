#include "sort.h"

/**
 * max_int - find the maximum value in an array of integers >= 0
 *
 * @array: The array of integers
 * @size: Number of elements in @array
 *
 * Return: The maximum value
 */
int max_int(int *array, size_t size)
{
	int max = 0;
	size_t i = 0;

	for (; i < size ; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *		 Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t k, i;
	ssize_t ssize, j;
	int *counts, *output;

	if (!array || size < 2)
		return;

	ssize = (ssize_t) size;
	k = max_int(array, size);
	counts = malloc(sizeof(*counts) * (k + 1));
	if (!counts)
	{
		perror("Insufficient memory");
		return;
	}

	for (i = 0 ; i < k ; i++)
		counts[i] = 0;
	for (i = 0 ; i < size ; i++)
		counts[array[i]]++;
	for (i = 1 ; i < k + 1 ; i++)
		counts[i] += counts[i - 1];

	print_array(counts, k + 1);

	output = malloc(sizeof(*output) * size);
	if (!output)
	{
		perror("Insufficient memory");
		return;
	}

	for (j = ssize - 1 ; j >= 0 ; j--)
		counts[array[j]]--,
		output[counts[array[j]]] = array[j];

	free(counts);
	for (i = 0 ; i < size ; i++)
		array[i] = output[i];
	free(output);
}
