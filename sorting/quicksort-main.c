#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.h"

static void groan(const char *msg)
{
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        groan("\n\t I need an element count for the test array.\n\n");
    }

    srand(time(NULL));

    long int size = strtol(argv[1], NULL, 10);

    if (errno == ERANGE || size < 1)
    {
        groan("\n The given size for the test array is out of range.");
    }


    int test[size];

    for (long int i = 0; i < size; i++)
    {
        test[i] = rand();
    }

    quicksort(test, size);

    printf("\n\tSimple in-place implementation output:\n\n");

    for (long int i = 0; i < size; i++)
    {
        printf("%d\n", test[i]);
    }

    r_quicksort(test, size);

    printf("\n\tRandomized in-place implementation output:\n\n");

    for (long int i = 0; i < size; i++)
    {
        printf("%d\n", test[i]);
    }
}
