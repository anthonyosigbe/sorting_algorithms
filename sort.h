#ifndef SORT_HEADER
#define SORT_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);

/*print_array*/
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_rec(int *array, int lower, int higher, size_t size);
int lomuto_partition(int *array, int lower, int higher, size_t size);
void counting_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int getCantRep(int num);
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
#endif

#endif
