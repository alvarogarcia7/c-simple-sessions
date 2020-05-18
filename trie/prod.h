#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

typedef struct trie{
    char *string;
    struct trie *next;
} trie;

static trie *trie_new() {
    return NULL;
}

static uint32_t trie_size() {
    return 0;
}

#endif //MAIN_H
