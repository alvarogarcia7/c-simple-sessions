#include <stdio.h>


#include "by_name.h"

int main(int argc, char **argv) {
    void (*ptr)(int, char **) = find_function(argv[1]);
    ptr(argc - 1, (argv + 1));
}