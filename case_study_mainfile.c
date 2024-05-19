#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    char repeat = 'y';
    int n = 0;
    struct Student *students = NULL;

    while (repeat == 'y' || repeat == 'Y') {
        printf("Menu:\n1. Enter Student Information\n2. Print Grade Card\n3. Insert Student Data\n4. Delete Student Data\nPress any other key to quit\nChoose an option (1-4): ");
        int choice;

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                Entry(&students, &n);
                break;
            case 2:
                searchAndDisplayStudent();
                break;
            case 3:
                insertStudent(&students, &n);
                break;
            case 4:
                deleteStudent(&students, &n);
                break;
            default:
                printf("Program terminated.\n");
                free(students);
                return 0;
        }

        printf("Do you wish to see the menu again y/n: ");
        scanf(" %c", &repeat);
    }

    free(students);
    return 0;
}

