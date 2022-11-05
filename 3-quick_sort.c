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
 * quick_sort_recursive - Sorts an array of integers in ascending order
 *			recursively using the Quick sort algorithm
 *			implementing 'Lomuto' partition scheme
 *
 * @arr: The ORIGINAL array being sorted
 * @len: Number of elements in @arr
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *arr, size_t len, int *array, size_t size)
{
	size_t p_idx, i;
	int pivot;

	if (!array || size < 2)
		return;

	pivot = array[size - 1];
	p_idx = 0;
	for (i = 0 ; i < size - 1 ; i++)
	{
		if (array[i] <= pivot) /* swap */
		{
			if (i > p_idx)
				swap(array + i, array + p_idx),
				print_array(arr, len);
			p_idx++;
		}
	}
	if (p_idx < size - 1)
		swap(array + size - 1, array + p_idx),
		print_array(arr, len);

	quick_sort_recursive(arr, len, array, p_idx);
	quick_sort_recursive(arr, len, array + p_idx + 1, size - p_idx - 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *		Quick sort algorithm implementing 'Lomuto' partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: wrapper function for quick_sort_recursive()
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, size, array, size);
}
