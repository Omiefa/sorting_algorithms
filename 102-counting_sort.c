#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, ind;

	for (max = array[0], ind = 1; ind < size; ind++)
	{
		if (array[ind] > max)
			max = array[ind];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_list, max, ind;

	if (array == NULL || size < 2)
		return;

	sorted_list = malloc(sizeof(int) * size);
	if (sorted_list == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted_list);
		return;
	}

	for (ind = 0; ind < (max + 1); ind++)
		count[ind] = 0;
	for (ind = 0; ind < (int)size; ind++)
		count[array[ind]] += 1;
	for (ind = 0; ind < (max + 1); ind++)
		count[ind] += count[ind - 1];
	print_array(count, max + 1);

	for (ind = 0; ind < (int)size; ind++)
	{
		sorted_list[count[array[ind]] - 1] = array[ind];
		count[array[ind]] -= 1;
	}

	for (ind = 0; ind < (int)size; ind++)
		array[ind] = sorted_list[ind];

	free(sorted_list);
	free(count);
}
