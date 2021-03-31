#include "prod.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void main_10_25(int argc, char **argv) {
    printf("AS 2D ARRAY:\n");
    // The limit of this approach is that all strings must have the same length: some content might be empty / some content not fitting
    // The benefit is that the memory is automatically managed
    char names_as_2d_array[3][12];

    strcpy((char *) names_as_2d_array, "PACIFIC");
    strcpy((char *) names_as_2d_array[1], "ATLANTIC");
    char *pString = names_as_2d_array[2];
    strcpy(pString, "CARIBBEAN");

    for (int i = 0; i < 3; ++i) {
        printf("'%s'\n", names_as_2d_array[i]);
    }

    printf("-----\n");
    printf("AS CHAR_POINTER ARRAY:\n");

    char *names_as_charpointer_array[4];
    names_as_charpointer_array[0] = calloc(12, sizeof(char));
    names_as_charpointer_array[1] = calloc(20, sizeof(char));
    names_as_charpointer_array[2] = calloc(4, sizeof(char));
    names_as_charpointer_array[3] = calloc(15, sizeof(char));

    // Using array syntax
    strcpy(names_as_charpointer_array[0], "BERING");

    // Using complicated syntax
    strcpy(*(&(*names_as_charpointer_array)+1), "BLACK");

    // Using char ** variable
    // Simplify the above syntax
    char **array_pointer = names_as_charpointer_array;
    strcpy(*(array_pointer + 2), "RED");

    names_as_charpointer_array[3][0] = '_';
    // Using pointer arithmetic at two levels (expect `_MEDITERRANIAN`)
    strcpy(*(names_as_charpointer_array + 3)+1, "MEDITERRANIAN");

    for (int i = 0; i < 4; ++i) {
        printf("'%s'\n", names_as_charpointer_array[i]);
    }

    free(names_as_charpointer_array[0]);
    free(names_as_charpointer_array[1]);
    free(names_as_charpointer_array[2]);
    free(names_as_charpointer_array[3]);
}
