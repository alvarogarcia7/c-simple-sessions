#include "prod.c"
#include "stdio.h"

void print_correctness(bool predicate);

char *remove_end_of_line(char *line);

int main() {
    trie_t *trie = trie_new();
    int return_code = 0;

    FILE *file_pointer = fopen("../resources/words_unique_100.txt","r");
    if(!file_pointer) {
        perror("File opening failed");
        return_code = EXIT_FAILURE;
        goto CLEANUP;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file_pointer) != EOF) {
        trie_add(trie, remove_end_of_line(line));
    }
    free(line);

//    trie_print(trie);

    for (int i = 0; i < trie->children; ++i) {
        free(trie->next[i]->string);
        free(trie->next[i]->next);
        free(trie->next[i]);
    }
    free(trie);

    return_code = 0;
    goto CLEANUP;

    CLEANUP:
    if(NULL != file_pointer){
        fclose(file_pointer);
    }
    return return_code;
}

char *remove_end_of_line(char *line) {
    size_t x = strlen(line);
    if('\n' == line[x] || '\r' == line[x]){
        line[x] = '\0';
    }
    x--;
    if(x >= 0 && '\n' == line[x] || '\r' == line[x]){
        line[x] = '\0';
    }

    return line;
}

void print_correctness(bool predicate) {
    char *result = predicate ? "OK" : "KO";
    printf("%s\n", result);
}
