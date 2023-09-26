#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @k: The first integer to swap.
 * @l: The second integer to swap.
 */
void swap_ints(int *k, int *l)
{
	int t;

	t = *k;
	*k = *l;
	*l = t;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t i, j;

	if (array == NULL)
    	return;
    if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minim = array + i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < *minim)
            {
                minim = array + j;
            }
        }
        
		if ((array + i) != minim)
		{
			swap_ints(array + i, minim);
			print_array(array, size);
		}
	}
}
