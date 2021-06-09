#include "prod.h"

int sum_r(int result, int *array, int remaining_length){
    if(0 == remaining_length){
        return result;
    }
    return sum_r(result + array[0], &array[1], remaining_length - 1);
}

int sum(int *array, int length) {
    return sum_r(0, array, length);
}

int reduce_subtract_r(int result, int *array, int remaining_length){
    if(0 == remaining_length){
        return result;
    }
    return sum_r(result - array[0], &array[1], remaining_length - 1);
}

int reduce_subtract(int *array, int length) {
    if (0 == length){
        return 0;
    }
    return reduce_subtract_r(array[0], &array[1], length - 1);
}

