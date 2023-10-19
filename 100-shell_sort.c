#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, temp;

	if (array == NULL || size < 2)
	return;

	while (gap < (int)size / 3)
	gap = gap * 3 + 1;

	while (gap > 0)
	{
	for (i = gap; i < (int)size; i++)
	{
		temp = array[i];
	j = i;

	while (j >= gap && array[j - gap] > temp)
	{
		array[j] = array[j - gap];
		j -= gap;
	}

		array[j] = temp;
	}
	print_array(array, size);
	gap = (gap - 1) / 3;
	}
}
