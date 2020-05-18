#include <stdint.h>
#include "prod.h"

trie *trie_new() {
    trie *trie = calloc(1, sizeof(struct trie));
    trie->next = NULL;
    return trie;
}

uint32_t trie_size(trie *trie) {
    return 0 + trie->next != NULL? 1 : 0;
}

void trie_add(trie *trie, char *string) {
    trie->string = string;
    trie->next = trie_new();
}

trie *trie_navigate(trie *trie, char *string) {
    return trie;
}
