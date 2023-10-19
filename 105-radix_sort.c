#include "sort.h"

/**
 * radix_sort - Sort an array using the radix sorting method.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Returns: This function does not return a value.
 */

void radix_sort(int *array, size_t size)
{
	int i, j, x, y, cantRep, max, div = 1, t = 0;
	int buckets[10][1000];

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 0; i < 10; ++i)
		for (j = 0; j < 1000; ++j)
			buckets[i][j] = -1;

	cantRep = getCantRep(max);

	for (i = 0; i < cantRep; ++i)
	{
		for (j = 0; j < (int) size; ++j)
		{
			for (y = 0; buckets[(array[j] / div) % 10][y] != -1; y++)
				;
			buckets[(array[j] / div) % 10][y] = array[j];
		}
		div = div * 10;
		t = 0;
		for (x = 0; x < 10; ++x)
		{
			for (y = 0; buckets[x][y] != -1; y++)
			{
				array[t] = buckets[x][y];
				buckets[x][y] = -1;
				t++;
			}
		}
		print_array(array, size);
	}
}

/**
 * getCantRep - Provides the count of digits in the largest
 * number within the array.
 * @num: The largest number in the array.
 *
 * Return: The count of digits in 'num'.
 */

int getCantRep(int num)
{
	bool flag = true;
	int cont = 0;

	while (flag)
	{
		flag = false;
		if (num > 0)
		{
			num = num / 10;
			cont++;
			flag = true;
		}
	}
	return (cont);
}
