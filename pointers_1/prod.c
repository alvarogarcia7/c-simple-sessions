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


void main_10_18(int argc, char **argv) {
    int *px, *py; /* integer pointers */
    static int a[6] = {1, 2, 3, 4, 5, 6};

    px = &a[0];
    py = &a[5];

    printf("px=%p, py=%p\n", px, py);
    unsigned long difference_by_pointers = py - px;
    printf("as pointers: py-px=%ld\n", difference_by_pointers);

    unsigned long difference_in_bytes = ((size_t)py - (size_t )px);
    printf("Difference in bytes: %lu bytes\n", difference_in_bytes);
    printf("Size of int = %ld bytes\n", sizeof(int));
    unsigned long number_of_positions = difference_in_bytes / sizeof(int);
    printf("%lu / %ld = %lu positions\n", difference_in_bytes, sizeof(int ), number_of_positions);
    printf("Is it the same? %s", number_of_positions == difference_by_pointers ? "true" : "false");
}

