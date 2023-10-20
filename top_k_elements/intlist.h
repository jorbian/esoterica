#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct intlist_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct intlist_s
{
	int n;
	struct intlist_s *next;
} intlist_t;

intlist_t *push(intlist_t **head, const int n);
size_t length(const intlist_t *h);
void free_intlist(intlist_t *head);
size_t print_intlist(const intlist_t *h);
intlist_t *cast_to_list(int *array, size_t len);
int get_max(intlist_t *ll_head);

#endif