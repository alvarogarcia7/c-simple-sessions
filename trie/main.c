#include <stdio.h>
#include "prod.c"

int main() {
    trie *trie = trie_new();
    trie_add(trie, "key");
    trie_add(trie, "keg");
    trie_print(trie);
    return 0;
}
