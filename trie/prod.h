#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdlib.h>

typedef struct trie{
    char *string;
    struct trie *next;
} trie;

static trie *trie_new();

static uint32_t trie_size(trie *trie);

static void trie_add(trie *trie, char *string);

#endif //MAIN_H
