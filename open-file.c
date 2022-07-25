#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "./headers/open-file.h"
#include "./headers/structures.h"

void open_file(FILE **fp, main_struct **sMain) {
    FILE *f = *fp;

    if (f != NULL) {
        printf("File already opened!\n");
        return;
    }

    // Open file
    f = fopen("./data/motoshow.db", "r");

    if (f == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    // Inflate main structure
    main_struct *sM = *sMain;
    sM = NULL;
    sM = (main_struct *) malloc(sizeof(main_struct) * 100);
    int counter = 0;
    
    while (!feof(f)) {
        char str[200] = {0};
        fscanf(f, "%s", str);
          
        char *token = strtok(str, ";");

        sM[counter].id = atoi(token);
        token = strtok(NULL, ";");

        strcpy(sM[counter].engine, token);
        token = strtok(NULL, ";");

        strcpy(sM[counter].frame, token);
        token = strtok(NULL, ";");

        sM[counter].mark = atoi(token);
        token = strtok(NULL, ";");

        sM[counter].type = atoi(token);
        token = strtok(NULL, ";");

        sM[counter].engine_volume = atoi(token);
        token = strtok(NULL, ";");

        sM[counter].power = atoi(token);
        token = strtok(NULL, ";");

        sM[counter].price = atof(token);

        counter++;
    }

    rewind(f);
    printf("File opened successfuly!\n");

    *sMain = sM;
    *fp = f;
    sM = NULL;
    f = NULL;
}