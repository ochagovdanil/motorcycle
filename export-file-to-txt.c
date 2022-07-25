#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/export-file-to-txt.h"
#include "./headers/structures.h"
#include "./headers/clear-screen.h"

void export_file_to_txt(main_struct **sMain) {
    clear_screen();

    main_struct *sM = *sMain;

    if (sM == NULL) {
        printf("Empty or open file at first!\n");
        return;
    }

    // Open directory files
    FILE *fp_mark = fopen("./data/mark.db", "r");
    FILE *fp_type = fopen("./data/type.db", "r");

    if (fp_mark == NULL || fp_type == NULL) {
        printf("Directory files not found!\n");
        exit(1);
    }

    // Inflate type structure
    type_struct *sType = (type_struct *) malloc(sizeof(type_struct) * 100);
    int typeCounter = 0;

    while (!feof(fp_type)) {
        char str[100] = {0};
        fgets(str, 100, fp_type);

        char *token = strtok(str, ";");

        sType[typeCounter].id = atoi(token);
        token = strtok(NULL, ";");

        strcpy(sType[typeCounter].type, token);

        typeCounter++;
    }

    // Inflate mark structure
    mark_struct *sMark = (mark_struct *) malloc(sizeof(mark_struct) * 100);
    int markCounter = 0;

    while (!feof(fp_mark)) {
        char str[100] = {0};
        fgets(str, 100, fp_mark);

        char *token = strtok(str, ";");
         
        sMark[markCounter].id = atoi(token);
        token = strtok(NULL, ";");
         
        strcpy(sMark[markCounter].mark, token);

        markCounter++;
    }

    // Create exported file
    FILE *fp_export = fopen("./exported/exported.txt", "w");

    // Write into exported file
    int struct_size = 0;
    while (1)
        if (sM[struct_size].id == 0) 
            break;
        else struct_size++;

    fprintf(fp_export, "%-5s | %-15s | %-15s | %-35s | %-25s | %-10s | %-10s | %-10s\n", "ID", "Engine", "Frame", "Mark", "Type", "Eng. Vol.", "Power", "Price");
    fprintf(fp_export, "----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < struct_size; i++) {
        char mark[50] = "ID not found";
        for (int k = 0; k < markCounter; k++) {
            if (sMark[k].id == sM[i].mark) {
                strcpy(mark, sMark[k].mark);
                break;
            }
        }

        char type[50] = "ID not found";
        for (int j = 0; j < typeCounter; j++) {
            if (sType[j].id == sM[i].type) {
                strcpy(type, sType[j].type);
                break;
            }
        }

        fprintf(fp_export, "%-5d | %-15s | %-15s | %-35s | %-25s | %-10d | %-10d | %-8.2f\n", sM[i].id, sM[i].engine, sM[i].frame, mark, type, sM[i].engine_volume, sM[i].power, sM[i].price);
    }

    fclose(fp_type);
    fclose(fp_mark);
    fclose(fp_export);
    fp_type = NULL;
    fp_mark = NULL;
    fp_export = NULL;
    sType = NULL;
    sMark = NULL;
    *sMain = sM;
    sM = NULL;

    printf("File exported successfuly! [./exported/exported.txt]\n");
}