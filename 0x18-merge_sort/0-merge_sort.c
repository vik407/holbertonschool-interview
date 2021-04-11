#include "sort.h"
/**
 * merge - merges two sorted arrays
 * @array: input array
 * @inner: inner array
 * @start: starting index
 * @mid: middle index
 * @end: ending index
 */
void merge(int *array, int *inner, int start, int mid, int end)
{
	int i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		if (array[i] < array[j])
			inner[k] = array[i++];
		else
			inner[k] = array[j++];
	while (i < mid)
		inner[k++] = array[i++];
	while (j < end)
		inner[k++] = array[j++];
	for (i = start, k = 0; i < end; i++)
		array[i] = inner[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
/**
 * ms - merge sort helper
 * @array: input array
 * @inner: inner array
 * @start: starting index
 * @end: ending index
 */
void ms(int *array, int *inner, int start, int end)
{
	int mid;

	if (end - start > 1)
	{
		mid = (end - start) / 2 + start;
		ms(array, inner, start, mid);
		ms(array, inner, mid, end);
		merge(array, inner, start, mid, end);
	};
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: input array
 * @size: length of array
 */
void merge_sort(int *array, size_t size)
{
	int *inner;

	if (!array || size < 2)
		return;
	inner = malloc(sizeof(int) * size);
	ms(array, inner, 0, size);
	free(inner);
}
