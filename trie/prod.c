#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "prod.h"

trie *trie_new() {
    trie *trie = calloc(1, sizeof(struct trie));
    trie->next[0] = NULL;
    return trie;
}

uint32_t trie_size(trie *trie) {
    struct trie *current = trie;
    uint32_t result = 0;
    while ((current = current->next[0]) != NULL) {
        result++;
    }
    return result;
}

void trie_add(trie *trie, char *string) {
//    size_t strspn(const char *str1, const char *str2)
//    Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
    if (trie->next[0] != NULL) {
        unsigned int matching_characters = strspn(trie->string, string);
        if (matching_characters == strlen(string)) {
            //need to split trie
            unsigned int rest_size = strlen(string) - matching_characters;
            char *first_part = calloc(matching_characters + 1, sizeof(char));
            strncpy(first_part, &(trie->string[0]), matching_characters);
//            printf("'%s'\n", first_part);
            char *second_part = calloc(rest_size + 1, sizeof(char));
            strncpy(second_part, &(trie->string[matching_characters]), strlen(string) + 1);
//            printf("'%s'\n", second_part);
            trie->string = first_part;
            struct trie *next = trie_new();
            next->string=second_part;
            next->next[0] = trie->next[0];
            trie->next[0] = next;
        }
    } else {
        trie->string = string;
        trie->next[0] = trie_new();
    }
}

trie *trie_navigate_recursive(trie *trie, char *string, char *temporary) {
    unsigned int matching_characters = strspn(trie->string, string);
    if (matching_characters == 0) {
        return NULL;
    }

    if (strcmp(trie->string, string) == 0) {
        return trie;
    }

    if (trie->next[0] != NULL) {
        strncpy(temporary, &string[matching_characters], 100);
        return trie_navigate_recursive(trie->next[0], temporary, temporary);
    }
}

trie *trie_navigate(trie *trie, char *string) {
    char *temporary = calloc(strlen(string) + 1, sizeof(char));
    strcpy(temporary, string);

    struct trie *result = trie_navigate_recursive(trie, string, temporary);

    free(temporary);

    return result;
}

static void trie_print(trie *trie) {
    while(trie->next != NULL){
        printf("'%s'\n", trie->string);
        trie = trie->next[0];
    }
}


