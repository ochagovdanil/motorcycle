#include <stdio.h>
#include <stdlib.h>

#include "./headers/edit-record-in-directory.h"
#include "./headers/clear-screen.h"

void edit_record_in_directory(FILE **fp_mark, FILE **fp_type) {
    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    // Open NANO editor
    if (fp_m != NULL) {
        system("nano -L ./data/mark.db");
        printf("Changes saved!\n");
    } else if (fp_t != NULL) {
        system("nano -L ./data/type.db");
        printf("Changes saved!\n");
    } else 
        printf("Select directory at first!\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}