#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/delete-record-from-directory.h"
#include "./headers/structures.h"
#include "./headers/clear-screen.h"

void delete_record_from_directory(FILE **fp_mark, FILE **fp_type) {
    FILE *fp_m = *fp_mark;
    FILE *fp_t = *fp_type;

    if (fp_m != NULL) {
        clear_screen();

        // Collect user data
        int desiredId, isFound = 0;

        printf("Enter record's ID you want to delete: ");
        scanf("%d", &desiredId);

        if (desiredId < 1) {
            printf("ID must be >= 1!\n");
            return;
        }

        // Find ID
        while (!feof(fp_m)) {
            char str[100] = {0};
            fgets(str, 100, fp_m);
               
            char *token = strtok(str, ";");

            if (desiredId == atoi(token)) {
                isFound = 1;
                break;
            }
        }

        rewind(fp_m);

        if (!isFound) 
            printf("Record not found!\n");
        else {
            // Rewrite file in order to delete record
            mark_struct *sMark = (mark_struct *) malloc(sizeof(mark_struct) * 100);
            int counter = 0;

            while (!feof(fp_m)) {
                char str[100] = {0};
                fgets(str, 100, fp_m);

                char *token = strtok(str, ";");

                if (desiredId == atoi(token)) 
                    continue;

                sMark[counter].id = atoi(token);
                token = strtok(NULL, ";");

                strcpy(sMark[counter].mark, token);

                counter++;
            }

            fclose(fp_m);
            fp_m = fopen("./data/mark.db", "w");

            for (int i = 0; i < counter; i++) {
                if (i == 0) // Without \n
                    fprintf(fp_m, "%d;%s;", sMark[i].id, sMark[i].mark);
                else
                    fprintf(fp_m, "\n%d;%s;", sMark[i].id, sMark[i].mark);
            }

            fclose(fp_m);
            fp_m = fopen("./data/mark.db", "r+");

            printf("\nRecord deleted successfuly!\n");
        }
    } else if (fp_t != NULL) {
        clear_screen();

        // Collect user data
        int desiredId, isFound = 0;

        printf("Enter record's ID you want to delete: ");
        scanf("%d", &desiredId);

        if (desiredId < 1) {
            printf("ID must be >= 1!\n");
            return;
        }

        // Find ID
        while (!feof(fp_t)) {
            char str[100] = {0};
            fgets(str, 100, fp_t);
               
            char *token = strtok(str, ";");

            if (desiredId == atoi(token)) {
                isFound = 1;
                break;
            }
        }

        rewind(fp_t);

        if (!isFound) 
            printf("Record not found!\n");
        else {
            // Rewrite file in order to delete record
            type_struct *sType = (type_struct *) malloc(sizeof(type_struct) * 100);
            int counter = 0;

            while (!feof(fp_t)) {
                char str[100] = {0};
                fgets(str, 100, fp_t);

                char *token = strtok(str, ";");

                if (desiredId == atoi(token)) 
                    continue;

                sType[counter].id = atoi(token);
                token = strtok(NULL, ";");

                strcpy(sType[counter].type, token);

                counter++;
            }

            fclose(fp_t);
            fp_t = fopen("./data/type.db", "w");

            for (int i = 0; i < counter; i++) {
                if (i == 0) // Without \n
                    fprintf(fp_t, "%d;%s;", sType[i].id, sType[i].type);
                else
                    fprintf(fp_t, "\n%d;%s;", sType[i].id, sType[i].type);
            }

            fclose(fp_t);
            fp_t = fopen("./data/type.db", "r+");

            printf("\nRecord deleted successfuly!\n");
        }
    } else 
        printf("Select directory at first!\n");

    *fp_mark = fp_m;
    *fp_type = fp_t;
    fp_m = NULL;
    fp_t = NULL;
}