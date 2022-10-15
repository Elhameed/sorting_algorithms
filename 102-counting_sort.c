#include "sort.h"

/**
 * _bigest -  Give me the largest number in a array of integers
 * @a: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *a, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < a[i])
			k = a[i];
	}
	return (k);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *aux = NULL, *array_sort = NULL;

	if (size < 2)
		return;
	/*Conocemos el numero mas grande del array*/
	k = _bigest(array, size);
	/*ayuda a crear el array*/
	aux = _memset(k + 1);
	if (!aux)
		return;
	/*Establecer los valores para ordenar*/
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				aux[j] += 1;
	/*Modifica el contador en el arrary*/
	for (i = 0; (int)i < k; i++)
		aux[i + 1] = aux[i] + aux[i + 1];
	print_array(aux, k + 1);
	/*Crea el array ordenada*/
	array_sort = malloc(size * sizeof(int));
	if (!array_sort)
	{
		free(aux);
		return;
	}
	for (i = 0; i < size; i++)
	{
		array_sort[aux[array[i]] - 1] = array[i];
		aux[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = array_sort[j];

	free(array_sort);
	free(aux);
}
