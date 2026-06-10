#include "notes.h"
#include "file_io.h"
#include <stdio.h>
#include <string.h>

#define MAX_NOTES 100

static Note notes[MAX_NOTES];
static int count = 0;
static int next_id = 1;
static int initialized = 0;

static void ensure_initialized() {
    if (!initialized) {
        reload_data(notes, &count);

        for (int i = 0; i < count; i++) {
            if (notes[i].id >= next_id) {
                next_id = notes[i].id + 1;
            }
        }

        initialized = 1;
    }
}

int add_note(const char *title, const char *content) {
    ensure_initialized();

    if (count >= MAX_NOTES)
        return -1;

    Note *current = &notes[count];
    current->id = (next_id)++;

    strncpy(current->title, title, sizeof(current->title) - 1);
    current->title[sizeof(current->title) - 1] = '\0';

    strncpy(current->content, content, sizeof(current->content) - 1);
    current->content[sizeof(current->content) - 1] = '\0';

    count++;

    batch_save(notes, count);

    return current->id;
}

int search_note(Note note_list[], int note_count, int target_id) {
    for (int i = 0; i < note_count; i++) {
        if (note_list[i].id == target_id) {
            return i;
        }
    }
    return -1;
}

int delete_note(int target_id) {
    ensure_initialized();

    int idx = search_note(notes, count, target_id);

    if (idx == -1) {
        return 0;
    }

    for (int i = idx; i < count - 1; i++) {
        notes[i] = notes[i + 1];
    }

    count--;

    batch_save(notes, count);

    return 1;
}

// =======================
// PUBLIC API (for Python)
// =======================

int api_add_note(const char *title, const char *content) {
    return add_note(title, content);
}

int api_delete_note(int id) {
    return delete_note(id);
}

int api_get_all_notes(Note *out, int max) {
    ensure_initialized();
    int n = (count < max) ? count : max;

    for (int i = 0; i < n; i++) {
        out[i] = notes[i];
    }

    return n;
}
