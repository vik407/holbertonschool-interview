#include "search_algos.h"

/**
 * print_array - prints an array
 * @array: input array
 * @start: starting index
 * @end: ending index
 */
void print_array(int *array, size_t start, size_t end)
{
	unsigned int i;

	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);
}

/**
 * ab - helper func for advanced binary
 * @array: input array
 * @start: starting index
 * @end: ending index
 * @value: value to search for
 * Return: index of array where value is found, -1 if not found
 */
int ab(int *array, int start, int end, int value)
{
	int mid;

	print_array(array, start, end);
	mid = ((end - start) / 2) + start;
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (start == end)
		return (-1);
	if (array[mid] >= value)
		return (ab(array, start, mid, value));
	if (array[mid] < value)
		return (ab(array, mid + 1, end, value));
	return (-1);
}


/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the advanced binary search algorithm
 * @array: input array
 * @size: size of array
 * @value: value to search for
 * Return: index of array where value is found, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (ab(array, 0, size - 1, value));
}
