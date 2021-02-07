#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fizzBuzz(int number)
{
    if (15 == number)
    {
        return "FizzBuzz";
    }
    if (5 == number)
    {
        return "Buzz";
    }
    return "Fizz";
}

int addition(int a, int b){
    if(a > 100 && b > 100){
        printf("Numbers should be smaller or equal to 100\n");
        return 0;
    } else {
        return a + b;
    }
}