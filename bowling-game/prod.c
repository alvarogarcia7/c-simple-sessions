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
    int result = 0;

    if(strlen(input) > 2) {
        char first_throw_2 = input[2];
        if (first_throw_2 == 'X') {
            result = 10;
        } else {
            char second_throw_2 = input[3];
            if (first_throw_2 == '-') {
                if (second_throw_2 == '-') {
                    result = 0;
                }
                if (numberCharToInt(second_throw_2) >= 1 && numberCharToInt(second_throw_2) <= 9) {
                    result = numberCharToInt(second_throw_2);
                }
            } else if (second_throw_2 == '-') {
                result = numberCharToInt(first_throw_2);
            } else if (second_throw_2 == '/') {
                result = 10;
            } else {
                result = numberCharToInt(first_throw_2) + numberCharToInt(second_throw_2);
            }
        }
    }

    char first_throw = input[0];
    if(first_throw == 'X'){
        return 10 + result;
    } else {
        char second_throw = input[1];
        if(first_throw == '-') {
            if (second_throw == '-') {
                return 0 + result;
            }
            if (numberCharToInt(second_throw) >= 1 && numberCharToInt(second_throw) <= 9) {
                return numberCharToInt(second_throw) + result;
            }
        } else if (second_throw == '-') {
            return numberCharToInt(first_throw) + result;
        } else if(second_throw == '/'){
            return 10 + result;
        } else {
            return numberCharToInt(first_throw) + numberCharToInt(second_throw) + result;
        }
    }
}

