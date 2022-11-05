#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *		Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t last, end, swapped = 1;
	int tmp;

	if (!array)
		return;

	end = last = size - 1;
	i = 0;
	while (i < size - 1)
	{
		if (!swapped)
			break;
		swapped = 0;
		for (j = 0 ; j < last; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				end = j;
				print_array(array, size);
			}
		}
		i++;
		last = end;
	}
}
