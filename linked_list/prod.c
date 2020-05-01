#include <stdlib.h>
#include "prod.h"

int_list *list_new() {
    int_list *p = calloc(1, sizeof(int_list));
    p->next = NULL;
    return p;
}

int64_t list_size(int_list *list) {
    int64_t result = 0;
    while (list->next != NULL) {
        list = list->next;
        result++;
    }
    return result;
}

void list_add(int_list *list, int64_t new_value) {
    while (list->next != NULL) {
        list = list->next;
    }
    int_list *next = calloc(1, sizeof(int_list));
    next->value = new_value;
    next->next = NULL;
    list->next = next;
}