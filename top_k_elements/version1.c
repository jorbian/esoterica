#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "topk.h"

static size_t range = 0;

static void show_counts(int **counts)
{
    size_t i;

    for (i = 0; i <= range; i++)
        printf("%d: %d\n", counts[i][0], counts[i][1]);
}

static int **initalize_counts()
{
    size_t i;

    int **new_count;

    new_count = malloc(sizeof(int *) * range + 1);
    if (new_count == NULL)
        return (NULL);

    for (i = 0; i <= range; i++)
    {
        new_count[i] = malloc(sizeof(int) * 2);
        if (new_count[i] == NULL)
        {
            return (NULL);
        }
        new_count[i][0] = i;
        new_count[i][1] = 0;
    }
    return (new_count);
}

static int **free_counts(int **counts)
{
    size_t i;

    if (counts == NULL)
        return (NULL);

    for (i = 0; i < range; i++)
        if (counts[i])
            free(counts[i]);

    free(counts);

    return (NULL);
}

static void count_numbers(intlist_t *ll_head, int **counts)
{
    intlist_t *list_ptr = ll_head;

    if (ll_head == NULL)
        return;

    do {
        counts[list_ptr->n][1]++;
    } while (list_ptr = list_ptr->next);
}

static void bubble_sort(int **counts, int k)
{
    size_t i, j;

    int *temp;

    for (i = 0; i < range; i++)
    {
        for (j = 0; j < range - i; j++) // Fix the loop condition
        {
            if (counts[j][1] < counts[j + 1][1])
            {
                temp = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp;
            }
        }
    }
}


static int *initalize_top_k(int k)
{
    int *new_top_k;

    new_top_k = malloc(sizeof(int) * k);
    if (new_top_k == NULL)
        return (NULL);

    return (new_top_k);
}

static int *take_top_k(int **counts, int k)
{
    size_t i;

    int *top;

    top = initalize_top_k(k);
    if (top == NULL)
        return (NULL);

    for (i = 0; i < k; i++)
        top[i] = counts[i][0];

    return (top);
}

int *top_k_elements(intlist_t *ll_head, int k)
{
    size_t i;

    int **counts = NULL, *top_k = NULL;

    if (!ll_head || k == 0)
        return (NULL);

    range = (size_t)get_max(ll_head);

    counts = initalize_counts(range);
    if (counts == NULL)
        return (NULL);

    count_numbers(ll_head, counts);
    bubble_sort(counts, k);

    top_k = take_top_k(counts, k);

    free(counts);

    return (top_k);
}
