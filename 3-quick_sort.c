#include "sort.h"

int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start_ind, int end_ind);

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int pivot, high, low;

	pivot = array[end];
	for (high = low = start; low < end; low++)
	{
		if (array[low] < pivot)
		{
			if (high < low)
			{
				swap(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > pivot)
	{
		swap(array + high, &array[end]);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start_ind: The starting index of the array partition to order.
 * @end_ind: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int start_ind, int end_ind)
{
	int mid;

	if (end_ind - start_ind > 0)
	{
		mid = lomuto_partition(array, size, start_ind, end_ind);
		lomuto_sort(array, size, start_ind, mid - 1);
		lomuto_sort(array, size, mid + 1, end_ind);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
