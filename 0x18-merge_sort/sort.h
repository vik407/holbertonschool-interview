#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* print funcs */
void print_array(const int *array, size_t size);

/* sorting algos */
void merge_sort(int *array, size_t size);

/* helpers */
void ms(int *array, int *inner, int start, int end);
void merge(int *array, int *inner, int start, int mid, int end);

#endif /* SORT_H */
