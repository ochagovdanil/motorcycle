#include <stdio.h>
#include "./headers/menu-edit.h"

int display_menu_edit() {
     int action;

     printf("1) Add record to file\n");
     printf("2) Delete record from file\n");
     printf("3) Edit record in file\n");
     printf("4) Back\n\n");

     scanf("%d", &action);

     if (action >= 1 && action <= 4) 
          return action;
     else 
          return -1;
}