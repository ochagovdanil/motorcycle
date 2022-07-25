#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/display-directory.h"
#include "./headers/structures.h"
#include "./headers/clear-screen.h"

void display_directory(FILE **fp_mark, FILE **fp_type) {
    clear_screen();

    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    if (fp_m != NULL) {
        // Inflate mark structure
        mark_struct *sMark = (mark_struct *) malloc(sizeof(mark_struct) * 100);
        int counter = 0;

        while (!feof(fp_m)) {
            char str[100] = {0};
            fgets(str, 100, fp_m);

            char *token = strtok(str, ";");
          
            sMark[counter].id = atoi(token);
            token = strtok(NULL, ";");
          
            strcpy(sMark[counter].mark, token);

            counter++;
        }

        // Print out directory
        printf("%-5s | %-35s\n", "ID", "Vehicle's Mark");
        printf("---------------------------------------\n");
        for (int i = 0; i < counter; i++)
            printf("%-5d | %-35s\n", sMark[i].id, sMark[i].mark);
          
        rewind(fp_m);
    } else if (fp_t != NULL) {
        // Inflate type structure
        type_struct *sType = (type_struct *) malloc(sizeof(type_struct) * 100);
        int counter = 0;

        while (!feof(fp_t)) {
            char str[100] = {0};
            fgets(str, 100, fp_t);

            char *token = strtok(str, ";");

            sType[counter].id = atoi(token);
            token = strtok(NULL, ";");

            strcpy(sType[counter].type, token);

            counter++;
        }

        // Print out directory
        printf("%-5s | %-25s\n", "ID", "Vehicle's Type");
        printf("---------------------------------------\n");
        for (int i = 0; i < counter; i++)
            printf("%-5d | %-25s\n", sType[i].id, sType[i].type);
        
        rewind(fp_t);
    } else 
        printf("Select directory at first!\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}