#include "notes.h"
#include <stdio.h>

int menu() {
    int chosen_menu_number;
    printf("\nWelcome to Memory Notes CLI App!\n");
    printf("\n1. Adding a Note\n");
    printf("2. Searching a Note\n");
    printf("3. Deleting a Note\n");
    printf("4. List All Notes\n");
    printf("5. Exit the Program\n");

    printf("\nEnter a Number: ");

    while (scanf("%d", &chosen_menu_number) != 1) {
        while (getchar() != '\n')
            ;

        printf("\nInvalid Input! Please Enter a Number: ");
    }
    while (getchar() != '\n')
        ;
    while (chosen_menu_number < 1 || chosen_menu_number > 5) {
        printf("\nWrong Number! Enter again: ");
        while (scanf("%d", &chosen_menu_number) != 1) {
            while (getchar() != '\n')
                ;

            printf("\nInvalid Input! Please Enter a Number: ");
        }
    }
    return chosen_menu_number;
}

void add_note(Note *current_note, int *next_id) {
    current_note->id = (*next_id)++;
    printf("Enter Title: ");
    fgets(current_note->title, sizeof(current_note->title), stdin);

    printf("Enter the Content: ");
    fgets(current_note->content, sizeof(current_note->content), stdin);

    printf("\nSaved the Note successfully!\n");
    printf("\nID: %d\n", current_note->id);
    printf("Title: %s\n", current_note->title);
    printf("Content: %s\n", current_note->content);
}

int search_note(Note note_list[], int note_count) {
    int target;
    printf("Enter ID: ");
    scanf("%d", &target);
    while (getchar() != '\n')
        ;

    for (int i = 0; i < note_count; i++) {
        if (note_list[i].id == target) {
            printf("Found!\n");
            printf("ID: %d\nTitle: %s\nContent: %s\n", note_list[i].id, note_list[i].title,
                   note_list[i].content);
            return i;
        }
    }

    printf("Not found\n");
    return -1;
}

void delete_note(Note note_list[], int *note_count, int idx) {
    for (int i = idx; i < *note_count - 1; i++) {
        note_list[i] = note_list[i + 1];
    }

    (*note_count)--;
    printf("Notes Left: %d\n", *note_count);
}

void list_notes(Note *note_list, int note_count) {
    if (note_count == 0) {
        printf("No Notes Available\n");
        return;
    }

    printf("\n--- Notes ---\n");

    for (int i = 0; i < note_count; i++) {
        printf("ID: %d | Title: %s\n", note_list[i].id, note_list[i].title);
    }
}
