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


/**
  *bubble_sort- A function that sorts an array of integers in ascending order
  *@array: the given array to be sorted
  *@size: size of the array
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
