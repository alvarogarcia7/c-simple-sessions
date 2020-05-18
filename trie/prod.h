#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdlib.h>

typedef struct trie{
    char *string;
    struct trie *next;
} trie;

static trie *trie_new() {
    trie *trie = calloc(1, sizeof(trie));
    trie->next = NULL;
    return trie;
}

static uint32_t trie_size(trie *trie) {
    return 0 + trie->next != NULL? 1 : 0;
}

static void trie_add(trie *trie, char *string) {
    trie->string = string;
    trie->next = trie_new();
}

#endif //MAIN_H
