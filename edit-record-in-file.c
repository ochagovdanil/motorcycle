#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/edit-record-in-file.h"
#include "./headers/structures.h"

void edit_record_in_file(FILE **fp, main_struct **sMain) {
    FILE *f = *fp;
    main_struct *sM = *sMain;

    if (f != NULL || sM != NULL) {
        printf("Close file before editing!\n");
        return;
    }

    // Open NANO editor
    system("nano -L data/motoshow.db");
     
    printf("Changes saved!\n");
}
