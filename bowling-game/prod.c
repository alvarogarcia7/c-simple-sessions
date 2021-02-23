#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberCharToInt(char input){
    return input - '0';
}

int score_calc(char *input){
    // input = ['X']: how we model it
    //           ^----0
    //              ^---- 1
    // input = ['X', '\0']: how it is in reality
    //                 ^----1

    printf("Input length = %lu\n", strlen(input));

    if(input[0] == 'X'){
        return 10;
    }
    if(input[0] == '-' && input[1] == '-'){
        return 0;
    }
    if (input[1] == '-') {
        return numberCharToInt(input[0]);
    } else if(input[1] == '/'){
        return 10;
    } else {
        return numberCharToInt(input[0]) + numberCharToInt(input[1]);
    }
}

