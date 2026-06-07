#include "file_io.h"
#include "notes.h"
#include <stdio.h>

int main(void) {

    reload_data(note_list[], int *note_count);

    Note note_list[100];
    int note_count = 0;

    while (1) {

        int choice = menu();

        switch (choice) {
        case 1: {
            add_note(&note_list[note_count], note_count + 1);
            note_count++;
            break;
        }
        case 2: {
            search_note(note_list, note_count);
            break;
        }
        case 3: {
            int idx = search_note(note_list, note_count);
            if (idx != -1) {
                delete_note(note_list, &note_count, idx);
            }
            break;
        } break;
        case 4: {
            batch_save(note_list[], int note_count);
            return 0;
        }
        }
    }
}
