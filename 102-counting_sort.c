#include "sort.h"

void counting_sort(int *array, size_t size) {
	if (array == NULL || size < 2) {
	return;  // Nothing to sort or invalid input
	}

	int max = get_max(array, size);

	int *count = calloc(max + 1, sizeof(int);
	if (count == NULL)
	{
	return;  // Memory allocation failed
	}

	// Count the occurrences of each element in the input array
	for (size_t i = 0; i < size; i++)
	{
	count[array[i]]++;
	}
    
	// Reconstruct the sorted array from the counting array
	size_t idx = 0;
	for (int i = 0; i <= max; i++)
	{
	while (count[i] > 0)
	{
		array[idx++] = i;
		count[i]--;
	}
	}

	free(count);
}

