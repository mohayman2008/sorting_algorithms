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

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
