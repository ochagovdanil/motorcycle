#include <stdio.h>
#include <stdlib.h>

#include "./headers/select-directory.h"
#include "./headers/clear-screen.h"

void select_directory(FILE **fp_mark, FILE **fp_type) {
    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    clear_screen();

    // Collect user data
    printf("1 - ./data/mark.db\n");
    printf("2 - ./data/type.db\n");
    printf("Select one [1,2]: ");

    int action;
    scanf("%d", &action);

    // Select directory
    if (action == 1) {
        if (fp_m) {
            printf("./data/mark.db already selected!\n");
            return;
        }

        fp_m = fopen("./data/mark.db", "r+");
        fp_t = NULL;

        if (fp_m)
            printf("./data/mark.db selected successfuly!\n");
        else 
            printf("Something went wrong...\n");
    } else if (action == 2) {
        if (fp_t) {
            printf("./data/type.db already selected!\n");
            return;
        }

        fp_t = fopen("./data/type.db", "r+");
        fp_m = NULL;

        if (fp_t)
            printf("./data/type.db selected successfuly!\n");
        else 
            printf("Something went wrong...\n");
    } else 
        printf("\nUnknown option...\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}