#include <stdio.h>
#include <stdlib.h>

#include "./headers/enter-to-continue.h"

void enter_to_continue() {
    printf("\n\nPress enter to continue: ");
    while (getchar() != '\r' && getchar() != '\n');
}