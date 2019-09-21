#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *merge(int *input1, int size1, int *input2, int size2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int *result = calloc(size1 + size2, sizeof(int));

    while (1)
    {
        if (i == size1 && j == size2)
        {
            break;
        }
        else if (i == size1)
        {
            result[k] = input2[j];
            k++;
            j++;
        }
        else if (j == size2)
        {
            result[k] = input1[i];
            i++;
            k++;
        }
        else if (input1[i] < input2[k])
        {
            result[k] = input1[i];
            i++;
            k++;
        }
        else
        {
            result[k] = input2[j];
            k++;
            j++;
        }
    }
    return result;
}

int *split_and_sort(int *input, int start, int end)
{
    int size1 = end - 0;
    int *input1 = calloc(size1, sizeof(int));
    memcpy(input1, input, size1 * sizeof(int));
    int *sorted1 = merge_sort(input1, size1);
    free(input1);
    return sorted1;
}

int *merge_sort(int *input, int input_length)
{
    if (input_length <= 1)
    {
        return input;
    }
    else
    {
        int marker = input_length / 2;

        int end;
        int begin;
        
        end = marker;
        begin = 0;
        int size1 = end - begin;
        int *input1 = calloc(size1, sizeof(int));
        memcpy(input1, input + begin, size1 * sizeof(int));
        int *sorted1 = merge_sort(input1, size1);

        begin = marker;
        end = input_length;
        int size2 = end - begin;
        int *input2 = calloc(size2, sizeof(int));
        memcpy(input2, input + begin, size2 * sizeof(int));
        int *sorted2 = merge_sort(input2, size2);

        int *result = merge(sorted1, size1, sorted2, size2);
        free(input1);
        free(input2);
        return result;
    }
}