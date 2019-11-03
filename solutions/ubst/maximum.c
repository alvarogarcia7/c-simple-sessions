#include <stdio.h>

int find_max(int *array1, int length)
{
    int max = array1[0];
    for (int i = 0; i< length; i++) 
    {
        if (array1[i] > max)
        {
            max = array1[i];
        }
    }

    return max;
}


