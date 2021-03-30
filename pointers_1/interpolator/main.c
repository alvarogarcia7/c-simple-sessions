#include <stdio.h>
#include "interpolate_template.h"

void usage(char *program_name) {
    printf("Usage: %s template_path main_list.txt generated.h\n", program_name);
}

int main(int argc, char **argv){
    if(argc < 4){
        usage(argv[0]);
        return -1;
    }

//    for (int i = 0; i < argc; ++i) {
//        printf("argv[%d] = %s\n", i, argv[i]);
//    }

    return hydrate_template(argv[3], argv[1], argv[2]);
}



