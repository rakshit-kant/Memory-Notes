#ifndef NOTES_H
#define NOTES_H

int menu();

typedef struct {
    int id;
    char title[64];
    char content[256];
} Note;

void add_note(Note *current_note, int *next_id);
int search_note(Note note_list[], int note_count);
void delete_note(Note note_list[], int *note_count, int idx);
void list_notes(Note note_list[], int note_count);

#endif
