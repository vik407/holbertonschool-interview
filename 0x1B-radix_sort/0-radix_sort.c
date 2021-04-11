#include "sort.h"
/**
* getMax - get max value
* @array:array
* @n: size
* Return: integer, max number of array
*/
int getMax(int *array, int n)
{
	int i, max;

	for (max = array[0], i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
* countSort - counting sort of arr[] according to the digit represented by exp
* @array:array
* @n:size
* @exp: exponential
* Return - None
*/
void countSort(int *array, int n, int exp)
{
	int *output, i, count[10] = { 0 };

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;
	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(output);
}
/**
* radix_sort - sort an array
* @array:array to be sorted
* @size:size of array
* Return - None
*/
void radix_sort(int *array, size_t size)
{
	int exp, m;

	if (size < 2)
		return;
	m = getMax(array, size);
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
