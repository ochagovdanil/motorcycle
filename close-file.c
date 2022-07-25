#include <stdio.h>
#include <stdlib.h>

#include "./headers/close-file.h"
#include "./headers/structures.h"

void close_file(FILE **fp, main_struct **sMain) {
    FILE *f = *fp;
    main_struct *sM = *sMain;

    if (f == NULL || sM == NULL) {
        printf("Open the file at first!\n");
        return;
    }

    fclose(f);
    f = NULL;
    sM = NULL;

    printf("File closed successfuly!\n");

    *sMain = sM;
    *fp = f;
    sM = NULL;
    f = NULL;
}