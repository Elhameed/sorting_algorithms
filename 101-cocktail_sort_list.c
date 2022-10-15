#include "sort.h"

/**
 * swap - function that swaps nodes in a linked
 * list of integers
 * @current_node: current position to swap
 * @next_node: next position to be swapped
 * @list: doubly linked list of integers
 * Return: void
 */
void swap(listint_t *current_node, listint_t *next_node, listint_t **list)
{
	/*mandamos el 99, mandamos el 71 y mandamos la cabeza 19*/
	/*el next del 99 apunta al 13*/
	current_node->next = next_node->next;
	/*el 13 existe ?*/
	if (current_node->next)
		/*el 13 prev apunta al 99*/
		current_node->next->prev = current_node;
	/*el 71 next apunta al 99*/
	next_node->next = current_node;
	/*el 71 prev apunta al 48*/
	next_node->prev = current_node->prev;
	/*el 48 existe ?*/
	if (next_node->prev)
		/*el 48 next apunta al 71*/
		next_node->prev->next = next_node;
	else
		*list = next_node;
	/*el 99 prev apunta al 71*/
	current_node->prev = next_node;

	print_list(*list);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail
 * shaker sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *front_runner, *back_runner;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	front_runner = (*list);
	back_runner = NULL;
	while (swapped == 1)
	{
		/*Here we are going forward*/
		swapped = 0;
		/*19, 48, 99, 71, 13, 52, 96, 73, 86, 7*/
		while (front_runner->next && front_runner != back_runner)
		{
			/*99 es mayor que 71 ?*/
			if (front_runner->n > front_runner->next->n)
			{
				swapped = 1;/*mandamos el 99, el 71 y la cabeza 19*/
				swap(front_runner, front_runner->next, list);
			}
			else
				front_runner = front_runner->next;
		}
		back_runner = front_runner;
		if (swapped == 0)
			break;
		/*Here we are going backward*/
		swapped = 0;
		while (front_runner->prev && front_runner != *list)
		{
			if (front_runner->n < front_runner->prev->n)
			{
				swapped = 1;
				swap(front_runner->prev, front_runner, list);
			}
			else
				front_runner = front_runner->prev;
		}
		*list = front_runner;
	}
}
