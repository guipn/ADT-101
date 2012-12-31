#include "list.h"
#include <stdio.h>
#include <stdbool.h>

static int as_int (void *promise)
{
    return *((int *) promise);
}

void print(void *int_val)
{
    printf("%d ", as_int(int_val));
}

int squared(void *int_val)
{
    return as_int(int_val) * as_int(int_val);
}

bool less_than_4(void *int_val)
{
    return as_int(int_val) < 4;
}

bool greater_than_3(void *int_val)
{
    return as_int(int_val) > 3;
}

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;
 
    list_t *list = cons(&a, cons(&b, cons(&c, cons(&d, empty()))));
    print_ints(list);

    list_t *dropped = drop(list, 1);
    print_ints(dropped);

    list_t *taken = take(2, dropped);
    print_ints(taken);

    (void) append(taken, &d);
    (void) append(taken, &c);
    for_each(taken, print);
    puts("");

    dropped = drop_while(taken, less_than_4);
    for_each(dropped, print);
    puts("");

    taken = take_while(dropped, greater_than_3);
    for_each(taken, print);
    puts("");

    destroy(taken);
}
