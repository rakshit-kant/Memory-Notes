#include "file_io.h"
#include "notes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int note_count = 0;
    int capacity = 10;

    Note *note_list = malloc(sizeof(Note) * capacity);
    if (note_list == NULL) {
        printf("Allocation Failed!");
        free(note_list);
        return 1;
    }

    reload_data(note_list, &note_count);

    int next_id = 1;

    while (1) {

        int choice = menu();

        switch (choice) {
        case 1: {
            if (note_count >= capacity) {
                capacity *= 2;

                Note *tmp = realloc(note_list, sizeof(Note) * capacity);

                if (tmp == NULL) {
                    printf("Reallocation of Memory Failed!");
                    return 1;
                }

                note_list = tmp;
            }

            for (int i = 0l; i < note_count; i++) {
                if (note_list[i].id >= next_id) {
                    next_id = note_list[i].id + 1;
                }
            }

            add_note(&note_list[note_count], &next_id);
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
        }
        case 4: {
            list_notes(note_list, note_count);
            break;
        }
        case 5: {
            batch_save(note_list, note_count);
            free(note_list);
            return 0;
        }
        }
    }
}
