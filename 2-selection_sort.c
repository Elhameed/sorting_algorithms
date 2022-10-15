#include "sort.h"

/**
 * selection_sort - function that sorts an array of
 * integers in ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin, aux;

	/*array = [64 25 12 22 11]*/
	for (i = 0; i < size - 1; i++)
	{
		/*Guardamos la posicion con el minimo valor*/
		jMin = i;
		/*Busca desde la posicion siguiente*/
		for (j = i + 1; j < size; j++)
		{
			/*Compara la posicion actual con la el array en la posicion i*/
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		/*Encontro un valor menor que la posicion inicial*/
		if (jMin != i)
		{
			aux = array[jMin];
			array[jMin] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}
