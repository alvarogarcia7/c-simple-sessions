#include <stdio.h>
#include "prod.c"

int main() {
    trie *trie = trie_new();
    trie_add(trie, "keyword");
    trie_add(trie, "key");
    char *string = trie_size(trie) == 2
                   ? "OK" : "KO";
    printf("%s\n", string);
    return 0;
}
