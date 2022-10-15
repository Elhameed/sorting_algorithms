#include "sort.h"

/**
 * merge - function that merges the two subarrays or array[]
 * back into one sorted array[].
 * of integers in ascending order using the
 * Merge sort algorithm
 * first array is the left[0:middle]
 * second array is the right[middle+1:size]
 * @array: array of integers
 * @left: left side of array of intigers
 * @right: right side of array of intigers
 * @size: lenght of array
 * Return: none
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int size_left = 0, size_right = 0;
	int i, j, k;

	i = j = k = 0;
	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);
	/* Merge the left and right arrays back into array[full-size]*/
	while (i < size_left && j < size_right)
	{
		/*Here in this conditional is where the magic happens and is sorted*/
		if (left[i] < right[j])
		{
			array[k] = left[i];
			i++; }
		else
		{
			array[k] = right[j];
			j++; }
		k++;
	}
	/* Copy the remaining elements of left[], if there are any*/
	while (i < size_left)
	{
		array[k] = left[i];
		i++;
		k++; }
	/* Copy the remaining elements of right[], if there are any*/
	while (j < size_right)
	{
		array[k] = right[j];
		j++;
		k++; }
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - function that sorts an array
 * of integers in ascending order using the
 * Merge sort algorithm
 * @array: array of integers
 * @size: lenght of array
 * Return: none
 */
void merge_sort(int *array, size_t size)
{
	/* create temporal arrays */
	int *left, *right, aux[1024];
	size_t i, j, middle;

	/*If the list is of length 0 or 1, then it is already sorted.*/
	if (array == NULL || size < 2)
		return;
	/*Divide the unsorted list into two sublists of about half the size.*/
	middle = size / 2;
	/*if we don't use the "&", we make pointer from integer without a cast*/
	left = aux;
	right = &aux[middle];

	/* Copy data to temp arrays left[] and right[] */
	for (i = 0; i < middle; i++)
		left[i] = array[i];
	for (j = middle; j < size; j++)
		right[j - middle] = array[j];
	/*Sort each sublist recursively by re-applying merge sort.*/
	merge_sort(left, middle);

