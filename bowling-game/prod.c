#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberCharToInt(char input){
    return input - '0';
}

int score_calc(char *input){
    if (input[1] == '-'){
        return numberCharToInt(input[0]);
    } else {
        return numberCharToInt(input[0]) + numberCharToInt(input[1]);
    }
}

