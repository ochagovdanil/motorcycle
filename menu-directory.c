#include <stdio.h>
#include "./headers/menu-directory.h"

int display_menu_directory() {
     int action;

     printf("1) Select directory\n");
     printf("2) Show current directory\n");
     printf("3) Display directory\n");
     printf("4) Edit record in directory\n");
     printf("5) Add record to directory\n");
     printf("6) Delete record from directory\n");
     printf("7) Back\n\n");

     scanf("%d", &action);

     if (action >= 1 && action <= 7) 
          return action;
     else 
          return -1;
}