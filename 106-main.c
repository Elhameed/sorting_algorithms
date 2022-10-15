#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int a[] = {100, 93, 40, 57, 14, 58, 85, 54,
	31, 56, 46, 39, 15, 26, 78, 13};
	size_t n = sizeof(a) / sizeof(a[0]);

	print_array(a, n);
	printf("\n");
	bitonic_sort(a, n);
	printf("\n");
	print_array(a, n);
	return (0);
}
