#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/add-record-to-file.h"
#include "./headers/structures.h"
#include "./headers/clear-screen.h"
 
void add_record_to_file(FILE **fp, main_struct **sMain) {
    FILE *f = *fp;
    main_struct *sM = *sMain;

    if (f == NULL || sM == NULL) {
        printf("Open the file at first!\n");
        return;
    }

    clear_screen();

    // Collect user data
    char engine[100];
    char frame[100];
    int mark;
    int type;
    int engine_volume;
    int power;
    float price;

    printf("Enter vehicle's engine name: ");
    scanf("%s", engine);
    if (strlen(engine) > 10) {
        printf("Engine name must be <= 10 characters!\n");
        return;
    }

    printf("Enter vehicle's frame name: ");
    scanf("%s", frame);
    if (strlen(frame) > 10) {
        printf("Frame name must be <= 10 characters!\n");
        return;
    }

    printf("Enter ID of vehicle's mark: ");
    scanf("%d", &mark);
    if (mark < 1) {
        printf("Mark's ID must be >= 1!\n");
        return;
    }

    printf("Enter ID of vehicle's type: ");
    scanf("%d", &type);
    if (type < 1) {
        printf("Type's ID must be >= 1!\n");
        return;
    }

    printf("Enter vehicle's engine volume: ");
    scanf("%d", &engine_volume);
    if (engine_volume < 100) {
        printf("Engine volume must be >= 100!\n");
        return;
    }

    printf("Enter vehicle's power: ");
    scanf("%d", &power);
    if (power < 10) {
        printf("Vehicle's power must be >= 10!\n");
        return;
    }

    printf("Enter vehicle's price in [RUB.KOP]: ");
    scanf("%f", &price);
    if (price < 1000) {
        printf("Vehicle's price must be >= 1_000.00 RUB!\n");
        return;
    }

    // Get last ID
    int struct_size = 0, lastId = 0;

    while (1)
        if (sM[struct_size].id == 0) 
            break;
        else {
            lastId = sM[struct_size].id;
            struct_size++;
        }

    // Insert record
    sM[struct_size].id = lastId + 1;
    strcpy(sM[struct_size].engine, engine);
    strcpy(sM[struct_size].frame, frame);
    sM[struct_size].mark = mark;
    sM[struct_size].type = type;
    sM[struct_size].engine_volume = engine_volume;
    sM[struct_size].power = power;
    sM[struct_size].price = price;

    printf("\nRecord inserted successfuly!\n");

    *sMain = sM;
    *fp = f;
    sM = NULL;
    f = NULL;
}