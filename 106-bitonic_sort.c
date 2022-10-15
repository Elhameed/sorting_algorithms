#include "sort.h"


/**
 * printcheck - print a range
 * @array: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * compAndSwap - swap two elements in an array
 * @a: THe array to change the values
 * @i: A index
 * @j: Another index
 * @dir: Direction of the array
 * Return: Nothing
 */
void compAndSwap(int *a, int i, int j, int dir)
{
	int aux;

	if (dir == (a[i] > a[j]))
	{
		aux = a[i];
		a[i] = a[j];
		a[j] = aux;
	}
}

/**
 * bitonicMerge - swap the elements to sort
 * @a: Array to sort
 * @low: The low element in the range to sort
 * @cnt: The size of the range to sort
 * @dir: Indicate which half are manage
 * @int_size: The size of the all array
 * Return: Nothing
 */
void bitonicMerge(int *a, int low, int cnt, int dir, const int int_size)
{
	int k = cnt, i = low;

	if (cnt > 1)
	{
		k = cnt / 2;

		for (i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);

		bitonicMerge(a, low, k, dir, int_size);
		bitonicMerge(a, low + k, k, dir, int_size);
	}
}

/**
 * bitonicSort - segmentate the array
 * @a: The array to sort
 * @low: The lowest element in each range
 * @cnt: Size of the range to sort
 * @dir: Indicate which half are manage
 * @int_size: The size of the all array
 * Return: Nothing
 */
void bitonicSort(int *a, int low, int cnt, int dir, const int int_size)
{
	int k = cnt;

	if (cnt > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", cnt, int_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", cnt, int_size);
		printcheck(a, low, low + k - 1);

		k = cnt / 2;
		bitonicSort(a, low, k, 1, int_size);

		bitonicSort(a, low + k, k, 0, int_size);

		bitonicMerge(a, low, cnt, dir, int_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", cnt, int_size);
			printcheck(a, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", cnt, int_size);
			printcheck(a, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int int_size = (int)size;

	if (size < 2 || !array)
		return;

	bitonicSort(array, 0, (int)size, up, int_size);
}
