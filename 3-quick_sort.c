#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive function for Quick Sort
 * @array: The array to be sorted
 * @lower: The lowest index of the partition
 * @higher: The highest index of the partition
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int recline = 0;

	if (lower < higher)
	{
		recline = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, recline - 1, size);
		quick_sort_rec(array, recline + 1, higher, size);
	}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: The array to be partitioned
 * @lower: The lowest index of the partition
 * @higher: The highest index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}
