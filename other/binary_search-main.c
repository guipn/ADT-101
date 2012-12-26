#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_search.h"

static void groan(const char *msg)
{
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
    (void) argc;

    if (!argv[1])
    {
        groan("\n\t I need an element count for the test array.\n\n");
    }

    long int size = strtol(argv[1], NULL, 10);

    if (errno == ERANGE || size < 1)
    {
        groan("\n The given size for the test array is out of range.");
    }


    if (!argv[2])
    {
        groan("\n\t My second parameter is the key for which to search.\n\n");
    }

    long int key = strtol(argv[2], NULL, 10);

    if (errno == ERANGE)
    {
        groan("\n The given key is invalid (out of bounds).");
    }



    int test[size];

    for (long int i = 0; i < size; i++)
    {
        test[i] = i;
    }

    printf("\n\t%d\n\n", binsearch(key, test, size));
}

