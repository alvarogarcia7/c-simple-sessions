#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void build_and_print_output(const FILE *output, const FILE *input);

int hydrate_template(char *output_path, char *template_path, char *main_lines_path) {
    FILE *template = NULL;
    FILE *output = NULL;
    FILE *main_lines = NULL;

    output = fopen(output_path, "w");
    if (output == NULL) {
        printf("output error\n");
        goto cleanup_and_fail;
    }

    template = fopen(template_path, "r");
    if (template == NULL) {
        printf("template error\n");
        goto cleanup_and_fail;
    }

    main_lines = fopen(main_lines_path, "r");
    if (main_lines == NULL) {
        printf("main_lines error\n");
        goto cleanup_and_fail;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, template)) != -1) {
        if (strstr(line, "@")) {
            build_and_print_output(output, main_lines);
        } else {
            fprintf(output, "%s", line);
        }
    }


    if (output != NULL) {
        fclose(output);
        output = NULL;
    }
    if (template != NULL) {
        fclose(template);
        template = NULL;
    }
    if (main_lines != NULL) {
        fclose(main_lines);
        main_lines = NULL;
    }

    return 0;


//    goto cleanup_and_fail;
//
    cleanup_and_fail:
    if (output != NULL) {
        fclose(output);
        output = NULL;
    }
    if (template != NULL) {
        fclose(template);
        template = NULL;
    }
    if (main_lines != NULL) {
        fclose(main_lines);
        main_lines = NULL;
    }

    return -1;
}

void build_and_print_output(const FILE *output, const FILE *input) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input)) != -1) {
        //by_name("10_12", main_10_12)
        line[read - 1] = 0;
        fprintf(output, "    by_name(\"%s\", %s)\n", line + 5, line);
    }
}

