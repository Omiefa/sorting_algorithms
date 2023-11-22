#include "sort.h"

/**
  *swap - Function that swaps two integers
  *@a: the first element to be swapped
  *@b: the second element to be swapped
  */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int *array, size_t size, size_t start, size_t root);

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @start: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t start, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < start && array[left] > array[large])
		large = left;
	if (right < start && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, start, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0);
	}
}
