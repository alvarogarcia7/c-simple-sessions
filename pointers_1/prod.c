#include "prod.h"
#include <stdio.h>

/* main */
void main_10_12(int argc, char **argv) {
    // Gottfried - Programming in C
    // Chapter 10 - Pointers
    // Example 10.12
    static int x[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    for (int i = 0; i < 10; ++i) {
        /* display an array element */
        printf("\ni= %d x[i]= %d *(x+i)= %d", i, x[i], *(x + i));

        /* display the corresponding array address */
        printf("   &x[i]= %p  x+i= %p", &x[i], (x + i));
    }
}

/* main */
void main_echo(int argc, char **argv) {
    printf("executed with %d\n", argc);

    for (int i = 0; i < argc; ++i) {
        printf("arg[%d] = %s\n", i, argv[i]);
    }
}

static char x[] = "This string is declared externally";
void main_10_14(int argc, char **argv) {

    char y[] = "This string is declared within main";

    printf("externally: %s, its address: %p\n", x, &x);
    printf("internally: %s, its address: %p\n", y, &y);

    // Both static:
    /*
externally: This string is declared externally, its address: 0x108ada080
internally: This string is declared within main, its address: 0x108ada050
     */

    // One static, one local
    /*
externally: This string is declared externally, its address: 0x102808060
internally: This string is declared within main, its address: 0x7ffeed3f9930
     */
}

