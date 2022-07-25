#include <stdio.h>
#include "./headers/menu-file.h"

int display_menu_file() {
     int action;

     printf("1) Open file\n");
     printf("2) Save file\n");
     printf("3) Close file\n");
     printf("4) Back\n\n");

     scanf("%d", &action);

     if (action >= 1 && action <= 4) 
          return action;
     else 
          return -1;
}