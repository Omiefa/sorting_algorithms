#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int a, int *tmp);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @a: The significant digit to sort on.
 * @tmp: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int a, int *tmp)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / a) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		tmp[count[(array[i] / a) % 10] - 1] = array[i];
		count[(array[i] / a) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, ni, *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	max = get_max(array, size);
	for (ni = 1; max / ni > 0; ni *= 10)
	{
		radix_counting_sort(array, size, ni, temp);
		print_array(array, size);
	}

	free(temp);
}
