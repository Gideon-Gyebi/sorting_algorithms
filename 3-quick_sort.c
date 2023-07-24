#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Ordering a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: Is the array of integers.
 * @size: Is the size of the array.
 * @left: Is the starting index of the subset to order.
 * @right: Is the ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implementing the quicksort algorithm through recursion.
 * @array: Is an array of integers to sort.
 * @size: Is the size of the array.
 * @left: Is the starting index of the array partition to order.
 * @right: Is the ending index of the array partition to order.
 *
 * Description: Useing the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - Sorting an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: Is an array of integers.
 * @size: Is the size of the array.
 *
 * Description: Useing the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
