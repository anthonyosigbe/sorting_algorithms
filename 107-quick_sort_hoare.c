#include "sort.h"

/**
 * swap_ints - Exchange the positions of two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Rearrange a segment of an array of integers
 *                   following the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the segment to be arranged.
 * @right: The ending index of the segment to be arranged.
 *
 * Return: The ultimate partition index.
 *
 * Description: This method employs the last element of the segment
 * as the pivot.
 * It also displays the array after every exchange of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Apply the quicksort algorithm recursively.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array partition to be arranged.
 * @right: The ending index of the array partition to be arranged.
 *
 * Description: This implementation utilizes the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Arrange an array of integers in ascending order
 *                   using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function applies the Hoare partition scheme and
 * prints the array after each exchange of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
