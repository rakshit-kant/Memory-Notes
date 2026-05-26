#include "notes.h"
#include <stdio.h>

int menu() {
    int chosen_menu_number;
    printf("Welcome to Memory Notes CLI App!\n");
    printf("1. -> Adding a Note\n");
    printf("2. -> Viewing a Note\n");
    printf("3. -> Deleting a Note\n");
    printf("4. -> Searching the program\n");
    printf("5. -> Exiting the program\n");

    printf("Enter a Number: ");

    while (scanf("%d", &chosen_menu_number) != 1) {
        while (getchar() != '\n')
            ;

        printf("Invalid Input! Please Enter a Number: ");
    }
    while (getchar() != '\n')
        ;

    if (chosen_menu_number < 1 || chosen_menu_number > 5) {
        (printf("Wrong Number! Enter a Correct Number!"));
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

void view_note(const Note *current_note) {
    printf("ID: %d\n", current_note->id);
    printf("Title: %s\n", current_note->title);
    printf("Content: %s\n", current_note->content);
}

void search_note() {
    // Placeholder
}

void delete_note() {
    // Placeholder
}
