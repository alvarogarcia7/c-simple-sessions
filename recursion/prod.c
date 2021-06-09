#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int *array, int length) {
    int result = 0;
    if (length > 0) {
        result += array[0];
    }
    if (length > 1) {
        result += array[1];
    }
    return result;
}

