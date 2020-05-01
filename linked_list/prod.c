#include <stdlib.h>
#include "prod.h"

// Private section

int_list *list_null_element();

int_list *list_new_element(int64_t new_value);

int_list *advance_to_the_end(int_list *list, int64_t *size);

// Public section implementation

int_list *list_new() {
    int_list *result = list_null_element();
    return result;
}

int64_t list_size(int_list *list) {
    int64_t size = 0;
    advance_to_the_end(list, &size);
    return size;
}

void list_add(int_list *list, int64_t new_value) {
    int64_t size = 0;
    list = advance_to_the_end(list, &size);
    list->next = list_new_element(new_value);
}

// Private section implementation

int_list *list_null_element() {
    int_list *result = list_new_element(0);
    return result;
}

int_list *list_new_element(int64_t new_value) {
    int_list *next = calloc(1, sizeof(int_list));
    next->value = new_value;
    next->next = NULL;
    return next;
}

int_list *advance_to_the_end(int_list *list, int64_t *size) {
    int64_t result = 0;
    while (list->next != NULL) {
        list = list->next;
        result++;
    }
    *size = result;
    return list;
}

