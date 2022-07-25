#include <stdio.h>
#include "./headers/menu-main.h"

int display_menu_main() {
     int action;

     printf("1) File\n");
     printf("2) Edit file\n");
     printf("3) Display file\n");
     printf("4) Export file to .txt\n");
     printf("5) Directory\n");
     printf("6) About\n");
     printf("7) Exit\n\n");

     scanf("%d", &action);

     if (action >= 1 && action <= 7) 
          return action;
     else 
          return -1;
}