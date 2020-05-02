#include <stdlib.h>
#include <stdio.h>
#include "prod.h"

// Private section

int_list *list_null_element();

int_list *list_new_element(int32_t new_value);

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

void list_add(int_list *list, int32_t new_value) {
    int64_t size = 0;
    list = advance_to_the_end(list, &size);
    list->value = new_value;
    list->next = list_null_element();
}

void list_add_at(int_list *list, int64_t position, int32_t value) {
    int64_t i = 0;
    while (list->next != NULL && i < position - 1) {
        list = list->next;
        i++;
    }
    int_list *previous_next = list->next;
    list->next = list_null_element();
    list->next->value = value;
    list->next->next = previous_next;
}

int32_t list_at(int_list *list, int64_t position) {
    int_list *llist = list;
    while (llist->next != NULL && position > 0) {
        llist = llist->next;
        position--;
    }
    return llist->value;
}

void list_delete(int_list *list, int64_t position) {
    int64_t i = 0;
    while (list->next != NULL && i < position) {
        list = list->next;
        i++;
    }
    list->value = list->next->value;
    list->next = list->next->next;
}

bool list_compare(int_list *list1, int_list *list2) {
    bool equals = true;
    while (true) {
        if (list1->next == NULL && list2->next == NULL) {
            break;
        } else if (list1->next != NULL && list2->next != NULL) {
            if (list1->value == list2->value) {
                list1 = list1->next;
                list2 = list2->next;
            } else {
                equals = false;
                break;
            }
        } else {
            equals = false;
            break;
        }
    }
    // Constant time
    while (list1->next != NULL) {
        list1 = list1->next;
    }
    while (list2->next != NULL) {
        list2 = list2->next;
    }
    //End constant time

    return equals;
}


// Private section implementation

int_list *list_null_element() {
    int_list *result = list_new_element(0);
    return result;
}

int_list *list_new_element(int32_t new_value) {
    int_list *next = calloc(1, sizeof(int_list));
    next->value = new_value;
    next->next = NULL;
    return next;
}

int_list *advance_to_the_end(int_list *list, int64_t *size) {
    while (list->next != NULL) {
        list = list->next;
        (*size)++;
    }
    return list;
}

