#ifndef NOTES_H
#define NOTES_H

int menu();

typedef struct {
    int id;
    char title[64];
    char content[256];
} Note;

void add_note(Note *, int);
int search_note(Note[], int);
void delete_note(Note[], int *, int);

#endif
