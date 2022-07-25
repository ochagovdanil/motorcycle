#include <stdio.h>
#include <stdlib.h>
#include "./headers/clear-screen.h"

void clear_screen() {
     #ifdef _WIN32
          system("cls");
     #endif
     #ifdef __unix__
          system("clear");
     #endif
}