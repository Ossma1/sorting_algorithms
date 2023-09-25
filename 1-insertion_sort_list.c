#include "sort.h"

/**
 * swap_nodes - Swap 2 nodes in a listint_t doubly-linked .
 * @ins: A pointer to the head of the doubly-linked .
 * @lis_n: A pointer to the 1 node to swap.
 * @lis_n2: The 2 node to swap.
 */
void swap_nodes(listint_t **ins, listint_t **lis_n, listint_t *lis_n2)
{
    if (*lis_n == NULL || lis_n2 == NULL)
        return;

    listint_t *temp_next = lis_n2->next;
    listint_t *temp_prev = lis_n2->prev;

    lis_n2->next = (*lis_n)->next;
    lis_n2->prev = *lis_n;

    if ((*lis_n)->next != NULL)
        (*lis_n)->next->prev = lis_n2;

    if ((*lis_n)->prev != NULL)
        (*lis_n)->prev->next = lis_n2;
    else
        *ins = lis_n2;

    (*lis_n)->next = temp_next;
    if (temp_next != NULL)
        temp_next->prev = *lis_n;

    *lis_n = temp_prev;
}
/**
 * insertion_sort_list - Sorts a doubly linked list  
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **listaa)
{
	listint_t *iter, *insert, *tmp;

	if (listaa == NULL || *listaa == NULL || (*listaa)->next == NULL)
		return;

	for (iter = (*listaa)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(listaa, &insert, iter);
			print_list((const listint_t *)*listaa);
		}
	}
}
