#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @n1: Pointer to the first number
 * @n2: Pointer to the second number
 */
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}


/**
 * sift_down - heapify a heap, when only the root is in wrong order
 *		by sifting it down
 *
 * @array: The array containg the heap
 * @size: Number of elements in @array
 * @root_idx: The index of the root of the heap
 * @end: The index of the last leaf in the heap
 */
void sift_down(int *array, size_t size, size_t root_idx, size_t end)
{
	size_t idx, c1, c2;

	if (root_idx == end)
		return;

	idx = root_idx;
	c1 = 2 * idx + 1;
	while (c1 <= end) /* array[idx] has at least 1 child */
	{
		c2 = 2 * idx + 2 <= end ? 2 * idx + 2 : 0;

		if (array[idx] >= array[c1] && (!c2 || array[idx] >= array[c2]))
			break;
		if (array[idx] < array[c1] && (!c2 || array[c1] >= array[c2]))
			swap(array + idx, array + c1),
			idx = c1;
		else
			swap(array + idx, array + c2),
			idx = c2;
		c1 = 2 * idx + 1;
		print_array(array, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *		Heap sort algorithm, The heap is constructed using
 *		sifting-down approach
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t ssize, end, i;

	if (!array || size < 2)
		return;

	ssize = (ssize_t) size;
	end = ssize - 1;
	for (i = (ssize - 2) / 2 ; i >= 0 ; i--)
		sift_down(array, size, i, end);

	while (end > 0)
	{
		swap(array, array + end);
		print_array(array, size);
		sift_down(array, size, 0, --end);
	}
}
