#include <stdio.h>
#include "prod.h"


int main() {
    int_list *list = list_new();

    list_add(list, 1);

    printf("size = %lld\n", list_size(list));
    return 0;
}