#ifndef PROD_H
#define PROD_H

#include <stdbool.h>

typedef struct int_list{
    int32_t value;
    struct int_list *next;

}int_list;

int_list *list_new();

int64_t list_size(int_list *);

void list_add(int_list *pList, int32_t value);

void list_add_at(int_list *pList, int64_t position, int32_t value);

int32_t list_at(int_list *pList, int64_t position);

void list_delete(int_list *pList, int64_t position);

bool list_compare(int_list *list1, int_list *list2);

#endif //PROD_H
