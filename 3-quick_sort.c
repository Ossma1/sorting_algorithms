#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpa;

	tmpa = *a;
	*a = *b;
	*b = tmpa;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivotaa).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int above1, below1;

	for (above1 = below1 = left; below1 < right; below1++)
	{
		if (*(array + right) > array[below1])
		{
			if (below1 > above1)
			{
				swap_ints(array + below1, array + above1);
				print_array(array, size);
			}
			above1++;
		}
	}

	if (*(array + right) < array[above1])
	{
		swap_ints(array + above1, array + right);
		print_array(array, size);
	}

	return (above1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{

	if (right - left > 0)
	{
		lomuto_sort(array, size, left, parlomuto_partition(array, size, left, right)t - 1);
		lomuto_sort(array, size, lomuto_partition(array, size, left, right) + 1, right);
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
	if (array == NULL)
        return;
    if (size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
