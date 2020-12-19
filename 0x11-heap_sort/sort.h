#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* print funcs */
void print_array(const int *array, size_t size);

/* sorting algos */
void heap_sort(int *array, size_t size);

/* helpers */
void swap(int *a, int *b);
void heapify(int *arr, int n, int i, size_t size);

#endif /* SORT_H */
