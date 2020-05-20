#include "prod.c"

void print_correctness(bool predicate);

int main() {
    trie_t *trie = trie_new();
    trie_add(trie, "kez");
    trie_add(trie, "keg");
    trie_add(trie, "kex");
    trie_print(trie);

    print_correctness(4 == trie_size(trie));

    for (int i = 0; i < trie->children; ++i) {
        free(trie->next[i]->string);
        free(trie->next[i]->next);
        free(trie->next[i]);
    }
    free(trie->string);
    free(trie);
    return 0;
}

void print_correctness(bool predicate) {
    char *result = predicate ? "OK" : "KO";
    printf("%s\n", result);
}
