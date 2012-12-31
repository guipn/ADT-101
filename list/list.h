#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    void *value;
    struct node *tail;
} list_t;


bool is_empty(list_t *);
list_t *append(list_t *, void *);
list_t *concat(list_t *, list_t *);
list_t *cons(void *, list_t *);
list_t *drop(list_t *, size_t);
list_t *drop_while(list_t *head, bool (*predicate)(void *));
list_t *empty(void);
list_t *next(list_t *);
list_t *snoc(list_t *, void *);
list_t *take(size_t, list_t *);
list_t *take_while(list_t *head, bool (*predicate)(void *));
size_t length(list_t *head);
void *nth(list_t *head, size_t n);
void destroy(list_t *);
void for_each(list_t *head, void (*f)(void *));
void print_ints(list_t *);

