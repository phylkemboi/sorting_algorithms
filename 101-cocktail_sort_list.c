#include "sort.h"

/**
 * list_len - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - function swaps nodes at pointer p with the following node
 * @list: head of list
 * @b: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **b)
{
	listint_t *one, *two, *three, *four;

	one = (*b)->prev;
	two = *b;
	three = (*b)->next;
	four = (*)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*b = three;
}

/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *b;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	b = *list;
	while (!sorted)
	{
		sorted = 1;
		while (b->next)
		{
			if (b->n > b->next->n)
			{
				sorted = 0;
				switch_nodes(list, &b);
				print_list(*list);
			}
			else
				b = b->next;
		}
		if (sorted)
			break;
		b = b->prev;
		while (b->prev)
		{
			if (b->n < b->prev->n)
			{
				sorted = 0;
				b = b->prev;
				switch_nodes(list, &b);
				print_list(*list);
			}
			else
				b = ->prev;
		}
	}
}
