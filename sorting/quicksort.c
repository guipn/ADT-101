#include <stdio.h>
#include <stdlib.h>

static size_t bad_partition(int array[], size_t p, size_t q);
static void   swap(int *a, int *b);
static void   ip_quicksort(int array[], size_t start, size_t size);

// The interface.

void quicksort(int array[], size_t size)
{
    ip_quicksort(array, 0, size);
}


static void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

 
// The in-place version of quicksort. The weakness of this implementation is in the
// bad_partition routine, which always picks the first element as the pivot.
// This makes the worst-case time O(n^2).
//
// The solution for that problem is to randomize the pivot choice.
// rquicksort will take care of that.

static void ip_quicksort(int array[], size_t start, size_t size) {

    if (start < size)
    {
        size_t pivot = bad_partition(array, start, size);

        ip_quicksort(array, start, pivot);
        ip_quicksort(array, pivot + 1, size);
    }
}


static size_t bad_partition(int array[], size_t p, size_t q) 
{
     int pivot = array[p];
     size_t i  = p;

    for (size_t j = p + 1; j < q; j++) 
    {
        if (array[j] < pivot) 
        {
            i++;
            swap(array + i, array + j);
        }
    }

    swap(array + p, array + i);
    return i;
}
