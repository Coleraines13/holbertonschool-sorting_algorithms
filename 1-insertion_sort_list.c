#include "sort.h"

/**
 * swap -swaps two elements
 * @list: pointer to thr head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 * Return: void
 */
void swap(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next;
	return;

	for (next = (*list)->next; next != NULL; next = next->next)
	{
		prev = next->prev;
		while (prev != NULL && prev->n > next->n)
		{
			swap(list, &prev, next);
			print_list(*list);
		}
	}
}
