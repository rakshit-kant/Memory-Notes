#include "notes.h"
#include <stdio.h>

int main() {
    Note note_list[100];
    int note_count = 0;

    while (1) {

        int choice = menu();

        switch (choice) {
        case 1:
            add_note(&note_list[note_count], note_count + 1);
            note_count++;
            break;
        case 2:
            int temp_id;
            printf("Enter the ID of the Note: ");
            scanf(" %d", &temp_id);

            if (temp_id < 0 || temp_id >= note_count) {
                while (getchar() != '\n')
                    ;
                printf("Invalid Input! Enter a Number");
                view_note(&note_list[temp_id]);
            }
            break;
        case 3:
            delete_note();
            break;
        case 4:
            search_note();
            break;
        case 5:
            return 0;
        }
    }
}
