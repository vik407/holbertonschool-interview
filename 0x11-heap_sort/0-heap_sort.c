#include "sort.h"
/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: input array
 * @size: length of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - turns array into heap
 * @arr: input array
 * @n: size of heap
 * @i: index at root
 * @size: size of array
 */
void heapify(int *arr, int n, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, size);
		heapify(arr, n, max, size);
	}
}

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
