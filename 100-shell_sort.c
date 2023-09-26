#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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
	size_t ga, i, j;

	if (array == NULL)
    	return;
    if (size < 2)
		return;

	for (ga = 1; ga < (size / 3);)
		ga = ga * 3 + 1;

	for (; ga >= 1; ga /= 3)
	{
		for (i = ga; i < size; i++)
		{
			j = i;
			while (j >= ga && array[j - ga] > array[j])
			{
				swap_ints(array + j, array + (j - ga));
				j -= ga;
			}
		}
		print_array(array, size);
	}
}
