#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "prod.h"

trie *trie_new() {
    trie *trie = calloc(1, sizeof(struct trie));
    trie->next = NULL;
    return trie;
}

uint32_t trie_size(trie *trie) {
    struct trie *current = trie;
    uint32_t result = 0;
    if (trie->next != NULL) {
        result++;
        int i = 0;
        while (current->next[i] != NULL && current->next[i]->next != NULL) {
            result++;
            i++;
        }
    }
    return result;
}

void trie_add(trie *trie, char *string) {
//    size_t strspn(const char *str1, const char *str2)
//    Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
    if (trie->next != NULL) {
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
            next->string = second_part;
            next->next = calloc(1, sizeof(struct trie *));
            trie->next[0] = next;
        } else if(matching_characters == strlen(trie->string)){
            //need to go deeper
            int i = 0;
            unsigned int rest_size = strlen(string) - matching_characters;
            char *second_part = calloc(rest_size + 1, sizeof(char));
            strncpy(second_part, &(string[matching_characters]), strlen(string) + 1);
            bool inserted = false;
            while (trie->next[i]->next != NULL) {
                unsigned int matching_characters = strspn(trie->next[i]->string, second_part);
                if(matching_characters > 0) {
                    trie_add(trie->next[i], second_part);
                    inserted = true;
                }
                i++;
            }
            if(!inserted){
                trie_add(trie->next[i], second_part);
            }
        } else if (matching_characters <= strlen(string)) {
            //need to split trie
            unsigned int rest_size = strlen(string) - matching_characters;
            char *shared_part = calloc(matching_characters + 1, sizeof(char));
            strncpy(shared_part, &(trie->string[0]), matching_characters);
            char *rest_of_first = calloc(rest_size + 1, sizeof(char));
            strncpy(rest_of_first, &(trie->string[matching_characters]), strlen(string) + 1);


            char *second_part = calloc(rest_size + 1, sizeof(char));
            strncpy(second_part, &(string[matching_characters]), strlen(string) + 1);
            struct trie *previousNext = trie->next[0];

            trie->string = shared_part;
            trie->next = calloc(2, sizeof(struct trie *));
            trie->next[0] = trie_new();
            trie->next[0]->string = rest_of_first;
            trie->next[0]->next = calloc(1, sizeof(struct trie *));
            trie->next[0]->next[0] = previousNext;

            trie->next[1] = trie_new();
            trie->next[1]->string = second_part;
            trie->next[1]->next = calloc(1, sizeof(struct trie *));;
            trie->next[1]->next[0] = trie_new();
        }
    } else {
        trie->string = string;
        trie->next = calloc(1, sizeof(struct trie *));
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

static void trie_print_recursive(int prefix, trie *trie) {
    printf("%d: '%s'\n", prefix, trie->string);
    int i = 0;
    while (trie->next[i] != NULL && trie->next[i]->next != NULL) {
        trie_print_recursive(prefix+1, trie->next[i]);
        i++;
    }
}

static void trie_print(trie *trie) {
    trie_print_recursive(0, trie);
}



