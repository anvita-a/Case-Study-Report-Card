#include <stdio.h>
#include "student.h"

int main() {
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        printf("Menu:\n1. Enter Student Information\n2. Print Grade Card\nPress any other key to quit\nChoose an option (1,2): ");
        int choice;

        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                Entry();
                break;
            case 2:
                searchAndDisplayStudent();
                break;
            default:
                printf("Program terminated.\n");
                break;
        }

        printf("Do you wish to see the menu again y/n: ");
        scanf(" %c", &repeat); 
    }
    return 0;
}

