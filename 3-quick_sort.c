#include "sort.h"

/**
 * partition - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @A: array of integers
 * @size: lenght of array
 * @low_index: low index
 * @high_index: high index
 * Return: none
 */
ssize_t partition(int *A, ssize_t low_index, ssize_t high_index, size_t size)
{
	/*pivote = al ultimo valor del array o la particion*/
	int pivot = A[high_index];
	ssize_t i = low_index, j; /*i = al indice minimo*/
	int aux;

	/* 10, 2, 8, 4, 5*/
	/*recorre el array o la particion*/
	for (j = low_index; j < high_index; j++)
	{
		/*si el valor del array en la posicion j es menor que el pivote*/
		if (A[j] < pivot)
		{
			if (A[i] != A[j])
			{
				/*hacemos el swap*/
				aux = A[j];
				A[j] = A[i];
				A[i] = aux;
				print_array(A, size);
			}
			i++;
		}
	}
	/*Cambia el ultimo o pivote con array en la posicion i*/
	if (A[i] != A[high_index])
	{
		aux = A[high_index];
		A[high_index] = A[i];
		A[i] = aux;
		print_array(A, size);
	}
	return (i);
}

/**
 * quicksort2 - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @A: array of integers
 * @size: lenght of array
 * @low_index: low index
 * @high_index: high index
 * Return: none
 */
void quicksort2(int *A, ssize_t low_index, ssize_t high_index, size_t size)
{
	ssize_t p = 0;


	if (low_index < high_index)
	{
		/*Divide y trae el punto pivote*/
		p = partition(A, low_index, high_index, size);
		/*hace recursion de la primera particion*/
		quicksort2(A, low_index, p - 1, size);
		/*hace recursion de la segunda particion*/
		quicksort2(A, p + 1, high_index, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort2(array, 0, size - 1, size);
}
