#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "prod.h"

void print_with_prefix(int prefix, char *string);

trie_t *trie_new() {
    return calloc(1, sizeof(trie_t));
}

uint32_t trie_size(trie_t *trie) {
    uint32_t result = trie->string == NULL ? 0:1;
    for (int i = 0; i < trie->children; i++) {
        result += trie_size(trie->next[i]);
    }
    return result;
}

void trie_add(trie_t *trie, char *string) {
//    size_t strspn(const char *str1, const char *str2)
//    Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
    if (trie->string != NULL) {
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
            trie->children++;
            trie_t *next = trie_new();
            next->string = second_part;
            trie->next = calloc(1, sizeof(trie_t *));
            trie->next[0] = next;
        } else if (matching_characters == strlen(trie->string)) {
            //need to go deeper
            unsigned int rest_size = strlen(string) - matching_characters;
            char *second_part = calloc(rest_size + 1, sizeof(char));
            strncpy(second_part, &(string[matching_characters]), strlen(string) + 1);
            bool inserted = false;
            for (int i = 0; i < trie->children; i++) {
                if (strspn(trie->next[i]->string, second_part) > 0) {
                    trie_add(trie->next[i], second_part);
                    inserted = true;
                }
            }
            if (!inserted) {
                trie_add(trie, second_part);
            }
        } else if (matching_characters == 0) {
            //need to append as child
            trie->children = 1;
            trie->next = calloc(1, sizeof(trie_t*));
            trie->next[0] = trie_new();
            trie->next[0]->string = string;

        } else if (matching_characters <= strlen(string)) {
            //need to split trie
            unsigned int rest_size = strlen(string) - matching_characters;
            char *shared_part = calloc(matching_characters + 1, sizeof(char));
            strncpy(shared_part, &(trie->string[0]), matching_characters);
            char *rest_of_first = calloc(rest_size + 1, sizeof(char));
            strncpy(rest_of_first, &(trie->string[matching_characters]), strlen(string) + 1);


            char *second_part = calloc(rest_size + 1, sizeof(char));
            strncpy(second_part, &(string[matching_characters]), strlen(string) + 1);
            trie_t **previousNext = trie->next;

            trie->string = shared_part;
            trie->children = 2;
            trie->next = calloc(2, sizeof(trie_t *));
            trie->next[0] = trie_new();
            trie->next[0]->string = rest_of_first;
            trie->next[0]->next = calloc(1, sizeof(trie_t *));
            trie->next[0]->next = previousNext;

            trie->next[1] = trie_new();
            trie->next[1]->string = second_part;
        }
    } else {
        trie->string = string;
        trie->children = 0;
    }
}

trie_t *trie_navigate_recursive(trie_t *trie, char *string, char *temporary) {
    unsigned int matching_characters = strspn(trie->string, string);
    if (matching_characters == 0) {
        return NULL;
    }

    if (strcmp(trie->string, string) == 0) {
        return trie;
    }

    trie_t *result;
    for(int i = 0; i < trie->children; i++) {
        if(strspn(trie->next[i]->string, string) == 0){
            continue;
        }
        size_t i1 = strlen(string) - matching_characters;
        strncpy(temporary, &string[matching_characters], i1);
        temporary[i1] = '\0';
        result = trie_navigate_recursive(trie->next[i], temporary, temporary);
        return result;
    }
    return NULL;
}

trie_t *trie_navigate(trie_t *trie, char *string) {
    char *temporary = calloc(strlen(string) + 1, sizeof(char));
    strcpy(temporary, string);

    trie_t *result = trie_navigate_recursive(trie, string, temporary);

    free(temporary);

    return result;
}

void print_with_prefix(int prefix, char *string) {
    for (int j = 0; j < prefix; j++) {
        printf("  ");
    }
    printf("'%s'\n", string);
}

static void trie_print_recursive(int prefix, trie_t *trie) {
    print_with_prefix(prefix, trie->string);
    for (int i = 0; i < trie->children; i++) {
        trie_print_recursive(prefix + 1, trie->next[i]);
    }
}

static void trie_print(trie_t *trie) {
    trie_print_recursive(0, trie);
}



