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
 * radix_sort - Sorts an array of integers in ascending order using
 *		LSD Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	ssize_t ssize, i, key, BASE = 10;
	int *counts, *output;
	int max, rank;

	if (!array || size < 2)
		return;

	ssize = (ssize_t) size;
	max = max_int(array, size);
	counts = malloc(sizeof(*counts) * (BASE));
	output = malloc(sizeof(*output) * size);

	if (!counts || !output)
	{
		perror("Insufficient memory");
		if (counts)
			free(counts);
		if (output)
			free(output);
		return;
	}
	for (rank = 1 ; max / rank > 0 ; rank *= BASE)
	{
		for (i = 0 ; i < BASE ; i++)
			counts[i] = 0;
		for (i = 0 ; i < ssize ; i++)
			counts[(array[i] / rank) % BASE]++;
		for (i = 1 ; i < BASE ; i++)
			counts[i] += counts[i - 1];
		for (i = ssize - 1 ; i >= 0 ; i--)
			key = (array[i] / rank) % BASE,
			counts[key]--,
			output[counts[key]] = array[i];
		for (i = 0 ; i < ssize ; i++)
			array[i] = output[i];
		print_array(array, size);
	}
	free(counts);
	free(output);
}
