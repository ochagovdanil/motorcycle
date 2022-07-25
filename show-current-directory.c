#include <stdio.h>
#include <stdlib.h>

#include "./headers/show-current-directory.h"
#include "./headers/clear-screen.h"

void show_current_directory(FILE **fp_mark, FILE **fp_type) {
    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    clear_screen();

    if (fp_m != NULL) 
        printf("./data/mark.db active now!\n");
    else if (fp_t != NULL) 
        printf("./data/type.db active now!\n");
    else 
        printf("There no selected directories yet!\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}