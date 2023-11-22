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
