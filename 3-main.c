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
	int a[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	/*int array[] = {10, 2, 8, 4, 5};*/
	size_t n = sizeof(a) / sizeof(a[0]);

	print_array(a, n);
	printf("\n");
	quick_sort(a, n);
	printf("\n");
	print_array(a, n);
	return (0);
}
