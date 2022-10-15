#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, aux;
	int bandera = 1;

	if (!array || !size)
		return;

	while (bandera != 0)
	{
		bandera = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				aux = array[i];
				array[i] = array[i - 1];
				array[i - 1] = aux;
				print_array(array, size);
				bandera = 1;
			}
		}
	}
}
