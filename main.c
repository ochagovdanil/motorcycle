#include <stdio.h>
#include <stdlib.h>

#include "./headers/clear-screen.h"
#include "./headers/about.h"
#include "./headers/enter-to-continue.h"
#include "./headers/structures.h"

#include "./headers/menu-main.h"
#include "./headers/menu-file.h"
#include "./headers/menu-edit.h"
#include "./headers/menu-directory.h"

#include "./headers/open-file.h"
#include "./headers/save-file.h"
#include "./headers/close-file.h"

#include "./headers/add-record-to-file.h"
#include "./headers/delete-record-from-file.h"
#include "./headers/edit-record-in-file.h"
#include "./headers/display-file.h"
#include "./headers/export-file-to-txt.h"

#include "./headers/select-directory.h"
#include "./headers/show-current-directory.h"
#include "./headers/display-directory.h"
#include "./headers/edit-record-in-directory.h"
#include "./headers/add-record-to-directory.h"
#include "./headers/delete-record-from-directory.h"

void show_menu();

// Public variables
FILE *fp = NULL;
FILE *fp_mark = NULL;
FILE *fp_type = NULL;
main_struct *sMain = NULL;

int main() {
     show_menu();
     return 0;
}

void show_menu() {
     while (1) {
          clear_screen();

          int action = display_menu_main();

          if (action == -1) {
               break;
          }

          switch (action) {
               case 1:
                    clear_screen();
                    int action = display_menu_file();

                    if (action == -1) 
                         break;

                    switch (action) {
                         case 1:
                              open_file(&fp, &sMain);
                              break;
                         case 2:
                              save_file(&fp, &sMain);
                              break;
                         case 3:
                              close_file(&fp, &sMain);
                    }
                    break;
               case 2:
                    clear_screen();
                    action = display_menu_edit();

                    if (action == -1)
                         break;

                    switch (action) {
                         case 1:
                              add_record_to_file(&fp, &sMain);
                              break;
                         case 2:
                              delete_record_from_file(&fp, &sMain);
                              break;
                         case 3:
                              edit_record_in_file(&fp, &sMain);
                    }
                    break;
               case 3:
                    display_file(&sMain);
                    break;
               case 4:
                    export_file_to_txt(&sMain);
                    break;
               case 5:
                    clear_screen();
                    action = display_menu_directory();

                    if (action == -1) 
                         break;

                    switch (action) {
                         case 1:
                              select_directory(&fp_mark, &fp_type);
                              break;
                         case 2:
                              show_current_directory(&fp_mark, &fp_type);
                              break;
                         case 3:
                              display_directory(&fp_mark, &fp_type);
                              break;
                         case 4:
                              edit_record_in_directory(&fp_mark, &fp_type);
                              break;
                         case 5:
                              add_record_to_directory(&fp_mark, &fp_type);
                              break;
                         case 6:
                              delete_record_from_directory(&fp_mark, &fp_type);
                              break;
                    }
                    break;
               case 6:
                    about();
                    break;
               case 7:
                    printf("Quitting the app...\n");
                    exit(0);
          } 

          enter_to_continue();
     }
}