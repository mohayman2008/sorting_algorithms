#include "sort.h"


/**
 * shell_sort - Sorts an array of integers in ascending order using
 *		 Shell sort algorithm, using Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	ssize_t ssize, gap = 1, i, j;
	int current;

	if (!array || size < 2)
		return;

	ssize = (ssize_t) size;
	while (gap < ssize / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap ; i < ssize ; i++)
		{
			current = array[i];
			for (j = i ; j >= gap - 1 && array[j - gap] > current ; j -= gap)
				array[j] = array[j - gap];
			array[j] = current;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
