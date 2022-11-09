#include "sort.h"

/**
 * bitonic_merge - Sorts and merge of integers according to the direction
 *		provided, using Bitonic sort algorithm
 *
 * @array: The array being merged
 * @size: Number of elements in @array
 * @dir: Direction of sorting (1) is ascending and (0) is descending
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t mid, i;
	int tmp;

	if (size < 2)
		return;

	mid = size / 2;
	if (2 * mid != size)
		return;
	for (i = 0 ; i < mid ; i++)
	{
		if (dir == (array[i] > array[i + mid]))
		{
			tmp = array[i];
			array[i] = array[i + mid];
			array[i + mid] = tmp;
		}
	}

	bitonic_merge(array, mid, dir);
	bitonic_merge(array + mid, mid, dir);
}

/**
 * bitonic_sort_r - Sorts of integers recursively according to the direction
 *		provided, using Bitonic sort algorithm
 *
 * @array: The array being sorted
 * @size: Number of elements in @array
 * @size_org: Number of elements in the original array (for printing)
 * @dir: Direction of sorting (1) is ascending and (0) is descending
 */
void bitonic_sort_r(int *array, size_t size, size_t size_org, int dir)
{
	size_t mid;
	char *dir_str;

	if (!dir)
		dir_str = "DOWN";
	else
		dir_str = "UP";

	if (size < 2)
		return;

	mid = size / 2;
	if (2 * mid != size)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, size_org, dir_str);
	print_array(array, size);

	bitonic_sort_r(array, mid, size_org, 1);
	bitonic_sort_r(array + mid, mid, size_org, 0);

	bitonic_merge(array, size, dir);

	printf("Result [%lu/%lu] (%s):\n", size, size_org, dir_str);
	print_array(array, size);
}


/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *		Bitonic sort algorith, by Wrapping bitonic_sort_r function
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_r(array, size, size, 1);
}
