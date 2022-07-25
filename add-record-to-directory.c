#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/add-record-to-directory.h"
#include "./headers/clear-screen.h"

void add_record_to_directory(FILE **fp_mark, FILE **fp_type) {
    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    if (fp_m != NULL) {
        clear_screen();

        // Collect user data
        char mark[100];

        printf("Enter vehicle's mark: ");
        getchar();
        fgets(mark, 100, stdin);
        mark[strlen(mark)-1] = 0; // Remove \n

        if (strlen(mark) > 30) {
            printf("Vehicle's mark must be <= 30 characters!\n");
            return;
        }

        // Get last ID
        int lastId = 0;

        while (!feof(fp_m)) {
            char str[100] = {0};
            fgets(str, 100, fp_m);

            char *token = strtok(str, ";");
            lastId = atoi(token);
        }

        // Insert record
        fseek(fp_m, 0L, SEEK_END);
        fprintf(fp_m, "\n%d;%s;", lastId+1, mark);
        rewind(fp_m);

        printf("\nRecord inserted successfuly!\n");
    } else if (fp_t != NULL) {
        clear_screen();

        // Collect user data
        char type[100];

        printf("Enter vehicle's type: ");
        getchar();
        fgets(type, 100, stdin);
        type[strlen(type)-1] = 0; // Remove \n

        if (strlen(type) > 20) {
            printf("Vehicle's type must be <= 20 characters!\n");
            return;
        }

        // Get last ID
        int lastId = 0;

        while (!feof(fp_t)) {
            char str[100] = {0};
            fgets(str, 100, fp_t);

            char *token = strtok(str, ";");
            lastId = atoi(token);
        }

        // Insert record
        fseek(fp_t, 0L, SEEK_END);
        fprintf(fp_t, "\n%d;%s;", lastId+1, type);
        rewind(fp_t);

        printf("\nRecord inserted successfuly!\n");
    } else 
        printf("Select directory at first!\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}