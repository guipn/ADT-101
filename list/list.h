#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    void *value;
    struct node *tail;
} list_t;


bool is_empty(list_t *);
list_t *cons(void *, list_t *);
list_t *drop(list_t *, size_t);
list_t *empty(void);
list_t *next(list_t *);
list_t *take(size_t, list_t *);
void destroy(list_t *);
void print_ints(list_t *);

/* Todo:
 *
 * append
 * map
 * for_each
 * nth
 * drop_while?
 * take_while?
 */
