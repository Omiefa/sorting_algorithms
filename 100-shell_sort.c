#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, indx1, indx2;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (indx1 = gap; indx1 < size; indx1++)
		{
			indx2 = indx1;
			while (indx2 >= gap && array[indx2 - gap] > array[indx2])
			{
				swap(array + indx2, array + (indx2 - gap));
				indx2 -= gap;
			}
		}
		print_array(array, size);
	}
}
