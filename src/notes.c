#include "notes.h"
#include <stdio.h>
#include <string.h>

int add_note(Note note_list[], int *note_count, int *next_id, const char *title,
             const char *content) {
    Note *current_note = &note_list[*note_count];

    current_note->id = (*next_id)++;

    strncpy(current_note->title, title, sizeof(current_note->title) - 1);

    current_note->title[sizeof(current_note->title) - 1] = '\0';

    strncpy(current_note->content, content, sizeof(current_note->content) - 1);

    current_note->content[sizeof(current_note->content) - 1] = '\0';

    (*note_count)++;

    return current_note->id;
}

int search_note(Note note_list[], int note_count, int target_id) {
    for (int i = 0; i < note_count; i++) {
        if (note_list[i].id == target_id) {
            return i;
        }
    }
    return -1;
}

int delete_note(Note note_list[], int *note_count, int target_id) {
    int idx = search_note(note_list, *note_count, target_id);

    if (idx == -1) {
        return 0;
    }

    for (int i = idx; i < *note_count - 1; i++) {
        note_list[i] = note_list[i + 1];
    }

    (*note_count)--;

    return 1;
}
