#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
    if (*n1 == NULL || n2 == NULL)
        return;

    listint_t *n1_prev = (*n1)->prev;
    listint_t *n1_next = (*n1)->next;
    listint_t *n2_prev = n2->prev;
    listint_t *n2_next = n2->next;

    if (n1_prev != NULL)
        n1_prev->next = n2;
    else
        *h = n2;

    if (n1_next != NULL)
        n1_next->prev = n2;

    n2->prev = n1_prev;
    n2->next = n1_next;

    if (n2_prev != NULL)
        n2_prev->next = *n1;

    if (n2_next != NULL)
        n2_next->prev = *n1;

    (*n1)->prev = n2_prev;
    (*n1)->next = n2_next;
    *n1 = n2;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted = NULL;  // La liste triée commence vide
	listint_t *current = *list;  // Nœud en cours de traitement

	while (current != NULL)
	{
		listint_t *next = current->next;  // Nœud suivant

		// Insérer current dans la liste triée
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;

			if (sorted != NULL)
				sorted->prev = current;

			sorted = current;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp->next != NULL && temp->next->n < current->n)
			{
				temp = temp->next;
			}

			current->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = current;

			temp->next = current;
			current->prev = temp;
		}

		current = next;
	}

	*list = sorted;  // Met à jour la liste originale
}
