#include "file_io.h"
#include <stdio.h>

int batch_save(Note note_list[], int note_count) {
    FILE *fp = fopen("notes.bin", "wb");

    if (fp == NULL) {
        printf("Failed to Read Line\n");
        return 1;
    }

    fwrite(note_list, sizeof(Note), note_count, fp);

    fclose(fp);
}

int reload_data(Note note_list[], int *note_count) {
    FILE *fp = fopen("notes.bin", "rb");

    if (fp == NULL) {
        *note_count = 0;
        return;
    }

    *note_count = fread(note_list, sizeof(Note), 100, fp);
}
