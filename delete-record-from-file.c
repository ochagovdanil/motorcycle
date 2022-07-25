#include <stdio.h>
#include <stdlib.h>

#include "./headers/delete-record-from-file.h"
#include "./headers/structures.h"
#include "./headers/clear-screen.h"
 
void delete_record_from_file(FILE **fp, main_struct **sMain) {
    FILE *f = *fp;
    main_struct *sM = *sMain;

    if (f == NULL || sM == NULL) {
        printf("Open the file at first!\n");
        return;
    }

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
    int struct_size = 0;
    while (1)
        if (sM[struct_size].id == 0) 
            break;
        else struct_size++;
     
    for (int i = 0; i < struct_size; i++)
        if (sM[i].id == desiredId) {
            isFound = 1;
            break;
        }

    if (!isFound) {
        printf("Record not found!\n");
    } else {
        // Delete record from main structure
        main_struct *sMainReplica = (main_struct *) malloc(sizeof(main_struct) * 100);
          
        int shouldDecrease = 0;
        for (int i = 0; i < struct_size; i++) 
            if (!shouldDecrease) {
                if (desiredId == sM[i].id) {
                    shouldDecrease = 1;
                    continue;
                }

                sMainReplica[i] = sM[i];
            } else 
                sMainReplica[i-1] = sM[i]; // Decrease index
          
        sM = NULL;
        sM = (main_struct *) malloc(sizeof(main_struct) * 100);

        for (int i = 0; i < (struct_size - 1); i++) 
            sM[i] = sMainReplica[i];

        *sMain = sM;
        *fp = f;
        sM = NULL;
        f = NULL;
        sMainReplica = NULL;
    }
}