#include <stdio.h>
#include <string.h>

void build_and_print_output(FILE *output, FILE *input);

int safe_close(FILE **pFile);

#define HYDRATE_TEMPLATE_CLEANUP \
safe_close(&output) \
+ safe_close(&template) \
+ safe_close(&main_lines)

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

    return HYDRATE_TEMPLATE_CLEANUP;

cleanup_and_fail:
    HYDRATE_TEMPLATE_CLEANUP;
    return -1;
}

int safe_close(FILE **output) {
    if (*output != NULL) {
        if(-1 == fclose(*output)) {
            return -1;
        }
        *output = NULL;
    }
    return 0;
}

void build_and_print_output(FILE *output, FILE *input) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input)) != -1) {
        // Expected output
        // by_name("10_12", main_10_12)
        line[read - 1] = 0;
        fprintf(output, "    by_name(\"%s\", %s)\n", line + 5, line);
    }
}

