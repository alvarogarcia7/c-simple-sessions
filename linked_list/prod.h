#ifndef PROD_H
#define PROD_H

typedef struct int_list{
    int value;
    struct int_list *next;

}int_list;

int_list *list_new();

int64_t list_size(int_list *);

#endif //PROD_H
