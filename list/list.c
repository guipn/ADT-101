#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *empty(void)
{
    return NULL;
}

bool is_empty(list_t *head)
{
    return head == empty();
}

list_t *next(list_t *head)
{
    if (is_empty(head))
    {
        perror(__func__);
    }

    return head->tail;
}


list_t *cons(void *value, list_t *tail)
{
    list_t *new = malloc(sizeof *new);

    if (!new)
    {
        perror("malloc");
    }

    new->value = value;
    new->tail  = tail;

    return new;
}


void destroy(list_t *head)
{
    for (list_t *cur = empty(); !is_empty(head); head = next(head))
    {
        cur = head;
        free(cur);
    }
}


list_t *take(size_t n, list_t *head)
{
    if (is_empty(head) || n == 0)
    {
        return empty();
    }

    list_t *taken      = head,
           *last_taken = empty();

    while (n > 0 && !is_empty(head))
    {
        last_taken = head;
        head = next(head);
        n--;
    }

    destroy(last_taken->tail);
    last_taken->tail = empty();

    return taken;
}


list_t *drop(list_t *head, size_t n)
{
    list_t *dropped = head;

    while (n > 0 && !is_empty(next(dropped)))
    {
        list_t *tmp = dropped;
        dropped     = next(dropped);
        free(tmp);
        n--;
    }

    return (n > 0) ? empty() : dropped;
}


void print_ints(list_t *head)
{
    if (is_empty(head))
    {
        puts("()");
    }
    else
    {
        printf("(");

        while (!is_empty(head) && !is_empty(next(head)))
        {
            printf("%d, ", *((int *) head->value));
            head = next(head);
        }

        printf("%d)\n", *((int *) head->value));
    }
}
