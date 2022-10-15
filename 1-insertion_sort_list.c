#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly
 * linked list of integers in ascending order using
 * the Insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux_runner;

	if (list == NULL || *list == NULL)
		return;
	/*para que arranque desde el 1*/
	aux_runner = (*list)->next;
	/*NULL, 19, 48, 9, 71, 13, NULL*/
	/*suponiendo que aux_runner es el 9*/
	while (aux_runner)
	{
		/*sortear*/
		while (aux_runner->prev && (aux_runner->n < aux_runner->prev->n))
		{
			/*el next del 48 ahora va a apuntar al 71*/
			aux_runner->prev->next = aux_runner->next;
			/*el 71 existe? esto es si no se encuentra en la ultima posicion*/
			/*el prev del 71 va a aputar al 48*/
			if (aux_runner->next)
				aux_runner->next->prev = aux_runner->prev;
			/*el next del 9 ahora va a apuntar al 48 (amarillo)*/
			aux_runner->next = aux_runner->prev;
			/*el prev del 9 va a apuntar al 19 (amarillo)*/
			aux_runner->prev = aux_runner->prev->prev;

			/*el prev del 48 pongalo a apuntar al 9*/
			aux_runner->next->prev = aux_runner;

			/*Esto es para mirar la cabeza*/
			if (aux_runner->prev == NULL)
				*list = aux_runner;
			else
				aux_runner->prev->next = aux_runner;

			print_list(*list);
		}
		/*avanzar*/
		aux_runner = aux_runner->next;

	}
}
