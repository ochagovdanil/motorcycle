#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "./headers/save-file.h"
#include "./headers/structures.h"

void save_file(FILE **fp, main_struct **sMain) {
    main_struct *sM = *sMain;

    if (fp == NULL || sM == NULL) {
        printf("Open the file at first!\n");
        return;
    }

    // Write data from structure to file
    FILE *f = *fp;
    fclose(f);
    f = fopen("./data/motoshow.db", "w");

    int struct_size = 0;
    while (1)
        if (sM[struct_size].id == 0) 
            break;
        else struct_size++;

    for (int i = 0; i < struct_size; i++) {
        if (i == 0) // Without \n
            fprintf(f, "%d;%s;%s;%d;%d;%d;%d;%.2f;", sM[i].id, sM[i].engine, sM[i].frame, sM[i].mark, sM[i].type, sM[i].engine_volume, sM[i].power, sM[i].price);
        else
            fprintf(f, "\n%d;%s;%s;%d;%d;%d;%d;%.2f;", sM[i].id, sM[i].engine, sM[i].frame, sM[i].mark, sM[i].type, sM[i].engine_volume, sM[i].power, sM[i].price);
    }

    fclose(f);
    f = fopen("./data/motoshow.db", "r");

    printf("File saved successfuly!\n");

    *sMain = sM;
    *fp = f;
    sM = NULL;
    f = NULL;
}
