#include "sort.h"

/**
 * swap_ints - Swap two integers within an array.
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
 * bitonic_merge - Sort a bitonic sequence in an integer array.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Start index of the sequence to sort.
 * @seq: Size of the sequence to sort.
 * @flow: Sorting direction.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Transform an array of integers into a bitonic sequence.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Start index of a block for building the bitonic sequence.
 * @seq: Size of the block for the bitonic sequence.
 * @flow: Sorting direction for the block.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Ascending order sorting of an integer array
 * using the bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: This function sorts the array in ascending order
 * and prints it after each swap. It is designed to work
 * with arrays whose size is a power of 2
 * (i.e., size = 2^k where k >= 0).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
