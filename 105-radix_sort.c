#include "sort.h"


/**
 * getMax - A utility function to get maximum value in arr[]
 * @arr: an unordered array a of length size
 * @size: lenght of array
 * Return: none
 */
int getMax(int *arr, size_t size)
{
	int mx = arr[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return (mx);
}

/* A function to do counting sort of arr[] according to */
/* the digit represented by exp. */
/**
 * countSort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @arr: an unordered array a of length size
 * @n: lenght of array
 * @exp: exp number
 * Return: none
 */
void countSort(int *arr, ssize_t n, int exp)
{
	int *output; /* array de salida */
	int count[10] = {0};
	ssize_t i;

	output = malloc(n * sizeof(int));
	if (!output)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	/* Change count[i] so that count[i] now contains actual */
	/*  position of this digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* contruir el array de salida */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/* Copy the output array to arr[], so that arr[] now */
	/* contains sorted numbers according to current digit */
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

/**
 * radix_sort - function that sorts an array of
 * integers in ascending order using the Radix sort algorithm
 * @array: an unordered array a of length size
 * @size: lenght of array
 * Return: none
 */
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int m, exp;

	if (!array || size < 2)
		return;

	m = getMax(array, size);
	/* Do counting sort for every digit. Note that instead */
	/* of passing digit number, exp is passed. exp is 10^i */
	/* where i is current digit number */
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
