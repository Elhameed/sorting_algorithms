#include "sort.h"
#define iLeftChild(x) (((x) * 2) + 1)
#define iRightChild(x) (((x) * 2) + 2)

/**
 * siftDown - function that repair the heap whose root
 * element is at index 'start', assuming the heaps rooted
 * at its children are valid)
 * @array: array of integers
 * @start: index start
 * @end: index end
 * @size: lenght array
 * Return: none
 */
void siftDown(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t root = start, child, swap;
	int aux;

	/*While the root has at least one child*/
	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root); /*(Left child of root)*/
		swap = root; /*(Keeps track of child to swap with)*/

		if (array[swap] < array[child])
			swap = child;
		/*If there is a right child and that child is greater)*/
		if ((child + 1 <= end) && (array[swap] < array[child + 1]))
			swap = child + 1;

		if (swap == root)
		{
			return;
		}
		else
		{
			/*swap(a[root], a[swap])*/
			aux = array[root];
			array[root] = array[swap];
			array[swap] = aux;
			print_array(array, size);
			/*repeat to continue sifting down the child now*/
			root = swap;
		}
	}
}

/**
 * heapify - function that put elements of 'a' in heap order, in-place)
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (((size - 1) - 1) / 2);
	/*start is assigned the index in 'array' of the last parent node*/
	/*the last element in a 0-based array is at index size-1*/
	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: an unordered array a of length size
 * @size: lenght of array
 * Return: none
 */
void heap_sort(int *array, size_t size)
{
	ssize_t end;
	int aux;

	if (!array || size < 2)
		return;

	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		aux = array[end];
		array[end] = array[0];
		array[0] = aux;
		print_array(array, size);

		/*the heap size is reduced by one*/
		end--;
		/*the swap ruined the heap property, so restore it*/
		siftDown(array, 0, end, size);
	}
}
