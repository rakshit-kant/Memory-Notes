#include "notes.h"
#include <stdio.h>

int menu() {
    int chosen_menu_number;
    printf("Welcome to Memory Notes CLI App!\n");
    printf("1. -> Adding a Note\n");
    printf("2. -> Searching a Note\n");
    printf("3. -> Deleting a Note\n");
    printf("4. -> Exiting the program\n");

    printf("Enter a Number: ");

    while (scanf("%d", &chosen_menu_number) != 1) {
        while (getchar() != '\n')
            ;

        printf("Invalid Input! Please Enter a Number: ");
    }
    while (getchar() != '\n')
        ;
    while (chosen_menu_number < 1 || chosen_menu_number > 4) {
        printf("Wrong Number! Enter again: ");
        scanf("%d", &chosen_menu_number);
    }
    return chosen_menu_number;
}

void add_note(Note *current_note, int id) {
    current_note->id = id;
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
    printf("COUNT: %d\n", *note_count);
}
