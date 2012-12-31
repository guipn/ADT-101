#include "list.h"
#include <stdio.h>
#include <stdbool.h>

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

    print_ints(taken);

    destroy(taken);
}
