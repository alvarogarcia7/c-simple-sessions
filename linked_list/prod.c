#include <stdlib.h>
#include "prod.h"

int_list *list_new() {
    return calloc(1, sizeof(int_list));
}

int64_t list_size(int_list *list) {
    int64_t result = 0;
    while (list->next != NULL) {
        result++;
    }
    return result;
}