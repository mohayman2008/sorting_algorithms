#include "sort.h"

/**
 * merge_sort_r - Sorts an array of integers in ascending order using
 *		Merge sort algorithm, using top-down implementation
 *
 * @buf: Memory allocated integers array buffer
 * @array: The array to be sorted
 * @size: Number of elements in @array and @buf
 */
void merge_sort_r(int *buf, int *array, size_t size)
{
	size_t mid_idx, i, itr1 = 0, itr2 = 0;
	int *h1, *h2;

	if (size < 2)
		return;

	mid_idx = size / 2;
	merge_sort_r(buf, array, mid_idx);
	merge_sort_r(buf + mid_idx, array + mid_idx, size - mid_idx);

	for (i = 0 ; i < size ; i++)
		buf[i] = array[i];
	h1 = buf;
	h2 = buf + mid_idx;

	printf("Merging...\n[left]: "), print_array(array, mid_idx);
	printf("[right]: "), print_array(array + mid_idx, size - mid_idx);

	for (i = 0 ; i < size ; i++)
	{
		if (itr1 >= mid_idx && itr2 >= size - mid_idx)
			break;
		if (itr1 >= mid_idx || ((itr2 < size  - mid_idx) && h1[itr1] >= h2[itr2]))
			array[i] = h2[itr2],
			itr2++;
		else
			array[i] = h1[itr1],
			itr1++;
	}
	printf("[Done]: "), print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *		Merge sort algorithm, using top-down implementation
 *		by Wrapping merge_sort_r function
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (!array || size < 2)
		return;

	buf = malloc(sizeof(*buf) * size);
	if (!buf)
	{
		perror("Insufficient memory");
		return;
	}

	merge_sort_r(buf, array, size);

	free(buf);
}
