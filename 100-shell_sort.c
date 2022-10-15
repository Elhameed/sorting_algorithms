#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, inner;
	int valueToInsert;

	if (array == NULL || size < 2)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			/* select value to be inserted */
			valueToInsert = array[i];
			inner = i;

			/*shift element towards right*/
			while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}

			/* insert the number at hole position */
			array[inner] = valueToInsert;
		}
		print_array(array, size);
		/* calculate interval*/
		interval = (interval - 1) / 3;
	}
}
