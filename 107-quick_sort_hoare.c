#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swapping two integers in an array.
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
 * hoare_partition - Ordering a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: Is the array of integers.
 * @size: Is the size of the array.
 * @left: Is the starting index of the subset to order.
 * @right: Is the ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implementing the quicksort algorithm through recursion.
 * @array: Is an array of integers to sort.
 * @size: Is the size of the array.
 * @left: Is the starting index of the array partition to order.
 * @right: Is the ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
		hoare_sort(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare - Sorting an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: Is an array of integers.
 * @size: Is the size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
