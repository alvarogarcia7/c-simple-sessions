#include "prod.h"
#include <stdio.h>
#include <stdlib.h>

void change_value(char (*input)[2]){
    printf("%c\n", input[1][0]);

    printf("modifying input\n");
    input[1][0] = '5';

    printf("%c\n", input[1][0]);
}

