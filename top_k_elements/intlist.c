#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "intlist.h"

/**
 * add_nodeint - adds a node at head of LL
 * @head: current LL head
 * @n: integer to populate in new list
 * 
 * Return: new linked list head
 */
intlist_t *push(intlist_t **head, const int n)
{
	intlist_t *newnode;

	newnode = malloc(sizeof(intlist_t));
	if (newnode == NULL)
		return (NULL);

	newnode->next = *head;
	newnode->n = n;

	*head = newnode;

	return (*head);
}

/**
 * intlist_len - reads LL and counts elements
 * @h: current head of LL
 * Return: number of elements as unsigned int
 */
size_t length(const intlist_t *h)
{
	int n;
	const intlist_t *tmp;

	for (n = 0, tmp = h; tmp; tmp = tmp->next, n++)
        ;

	return (n);
}

/**
 * free_intlist - frees memory used by a LL
 * @head: head of LL
 * Return: None
 */

void free_intlist(intlist_t *head)
{
	intlist_t *temp = head;

	while (temp->next)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	free(temp);
}

/**
 * print_intlist - prints all elements of a list storing ints
 * @h: current head of LL
 * Return: number of elements as unsigned int
 */
size_t print_intlist(const intlist_t *h)
{
	int n;
	const intlist_t *tmp;

	for (n = 0, tmp = h; tmp; tmp = tmp->next, n++)
		printf("%d\n", tmp->n);

	return (n);
}

intlist_t *cast_to_list(int *array, size_t len)
{
    size_t i;

    intlist_t *new_list = NULL;

    for (i = 0; i < len; i++)
        push(&new_list, array[i]);

    return (new_list);
}

int get_max(intlist_t *ll_head)
{
    int max = 0;

    intlist_t *list_ptr = NULL;

    if (ll_head == NULL)
        return (max);

    list_ptr = ll_head;
    max = list_ptr->n;

    while (list_ptr = list_ptr->next)
        if (list_ptr->n > max)
            max = list_ptr->n;

    return (max);
}