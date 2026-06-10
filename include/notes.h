#ifndef NOTES_H
#define NOTES_H

typedef struct {
    int id;
    char title[64];
    char content[256];
} Note;

int add_note(const char *title, const char *content);

int search_note(Note note_list[], int note_count, int target_id);

int delete_note(int target_id);

int api_add_note(const char *title, const char *content);
int api_get_all_notes(Note *out, int max);
int api_delete_note(int id);

#endif
