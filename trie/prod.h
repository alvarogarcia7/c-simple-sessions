#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdlib.h>

typedef struct trie_t{
    char *string;
    uint8_t children;
    bool is_end_of_word;
    struct trie_t **next;
} trie_t;

static trie_t *trie_new();

static uint32_t trie_size(trie_t *trie);

static void trie_add(trie_t *trie, char *string);

static trie_t *trie_navigate(trie_t *trie, char *string);

static void trie_print(trie_t *trie);

#endif //MAIN_H
