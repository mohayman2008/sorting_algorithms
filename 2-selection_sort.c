#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *	        Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int min, tmp;

	if (!array || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		min = array[i];
		min_idx = i;
		for (j = i ; j < size ; j++)
		{
			if (array[j] < min)
				min = array[j],
				min_idx = j;
		}

		if (min_idx != i) /* swap */
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}

	}
}
