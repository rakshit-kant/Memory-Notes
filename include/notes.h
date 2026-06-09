#ifndef NOTES_H
#define NOTES_H

typedef struct {
    int id;
    char title[64];
    char content[256];
} Note;

int add_note(Note note_list[], int *note_count, int *next_id, const char *title,
             const char *content);

int search_note(Note note_list[], int note_count, int target_id);

int delete_note(Note note_list[], int *note_count, int target_id);

#endif
