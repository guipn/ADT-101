#include <stdlib.h>

int binsearch(int key, int *array, size_t length)
{
    size_t i = length / 2;
 
    while (i < length)
    {
        if (array[i] == key)
        {
            return i;
        }
 
        if (array[i] < key)
        {
            i += (length - i + 1) / 2;
        }
        else
        {
            length = i;
            i /= 2;
        }
    }
 
    return -1;
}

