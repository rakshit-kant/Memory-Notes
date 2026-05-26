#ifndef NOTES_H
#define NOTES_H

typedef struct {
    int id;
    char title[100];
    char content[500];
} Note;

int menu();
void add_note(Note *note);
void view_note(const Note *note);
void delete_note();
void search_note();
#endif
