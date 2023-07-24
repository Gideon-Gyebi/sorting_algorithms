#include "sort.h"

/**
 * swap_ints - Swaping two integers in an array.
 * @a: Is the first integer to swap.
 * @b: Is the second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorting an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Is an array of integers.
 * @size: Is the size of the array.
 *
 * Description: Printing the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
