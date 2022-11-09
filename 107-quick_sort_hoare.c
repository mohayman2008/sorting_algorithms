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
 * quick_sort_hoare_r - Sorts an array of integers in ascending order
 *			recursively using the Quick sort algorithm
 *			implementing 'Hoare' partition scheme
 *
 * @arr: The ORIGINAL array being sorted
 * @len: Number of elements in @arr
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *arr, size_t len, int *array, size_t size)
{
	size_t itr1, itr2, idx;
	int pivot;

	if (!array || size < 2)
		return;

	pivot = array[size - 1];
	itr1 = 0;
	itr2 = size - 1;

	while (itr2 > itr1)
	{
		while (array(itr1) < pivot)
			itr1++;
		while (array(itr2) > pivot)
			itr2--;
		if (itr1 >= itr2)
		{
			if (array[itr1] == pivot)
				idx = itr1;
			else
				idx = itr2;
			break;
		}
		swap(array + itr1, array + itr2);
		print_array(arr, len);
	}

	quick_sort_recursive(arr, len, array, p_idx + 1);
        quick_sort_recursive(arr, len, array + p_idx + 1, size - p_idx - 1);
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *			Quick sort algorithm implementing 'Hoare' partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: wrapper function for quick_sort_recursive()
 */
void quick_sort_hoare(int *array, size_t size);
{
	quick_sort_hoare_r(array, size, array, size);
}
