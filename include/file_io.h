#ifndef FILE_IO_H
#define FILE_IO_H

#include "notes.h"

int batch_save(Note note_list[], int note_count);
int reload_data(Note note_list[], int *note_count);

#endif
