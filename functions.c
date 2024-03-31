#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayStudentDetails(struct Student *student) {
    printf("SRN: %s\n", student->srn);
    printf("Name: %s\n", student->name);
    printf("Semester: %d\n", student->sem);
    printf("Section: %c\n", student->sec);
    for (int k = 0; k < MAX_EXAMS; k++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Marks for ISA%d Subject%d: %.2f\n", k + 1, j + 1, student->Marks[k][j]);
        }
    }
    printf("Total Marks for ISA1: %.2f\n", student->exam1_tot);
    printf("Total Marks for ISA2: %.2f\n", student->exam2_tot);
    printf("Total Marks for ISA3: %.2f\n", student->exam3_tot);
    printf("Total Marks for Subject1: %.2f\n", student->sub1_tot);
    printf("Total Marks for Subject2: %.2f\n", student->sub2_tot);
    printf("Total Marks for Subject3: %.2f\n", student->sub3_tot);
    printf("Total Marks across all exams and subjects: %.2f\n", student->total);
    printf("Grade for ISA1: %c\n", student->exam1_grade);
    printf("Grade for ISA2: %c\n", student->exam2_grade);
    printf("Grade for ISA3: %c\n", student->exam3_grade);
    printf("Grade for Subject1: %c\n", student->sub1_grade);
    printf("Grade for Subject2: %c\n", student->sub2_grade);
    printf("Grade for Subject3: %c\n", student->sub3_grade);
    printf("\n");
}

int Entry() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    scanf("%*c");

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("SRN: ");
        scanf("%6s", students[i].srn);
        scanf("%*c");

        printf("NAME: ");
        scanf("%67[^\n]", students[i].name);
        scanf("%*c");

        printf("SEMESTER: ");
        scanf("%d", &students[i].sem);
        scanf("%*c");

        while (students[i].sem < 1 || students[i].sem > 10) {
            printf("The semester number is wrong. Enter the correct semester number: ");
            scanf("%d", &students[i].sem);
            scanf("%*c");
        }

        printf("SECTION: ");
        scanf("%c", &students[i].sec);
        scanf("%*c");

        printf("MARKS:\n");
        for (int k = 0; k < MAX_EXAMS; k++) {
            printf("Enter the marks for ISA%d: \n", k + 1);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("Enter the marks for subject%d out of 100: ", j + 1);
                scanf("%f", &students[i].Marks[k][j]);
            }
            printf("\n");
        }

        // Calculate totals and grades here
        float tot_exam1 = 0, tot_exam2 = 0, tot_exam3 = 0, tot_sub1 = 0, tot_sub2 = 0, tot_sub3 = 0, total = 0;

        for (int m = 0; m < MAX_EXAMS; m++) {
            for (int l = 0; l < MAX_SUBJECTS; l++) {
                if (m == 0) {
                    tot_exam1 += students[i].Marks[m][l];
                }
                if (m == 1) {
                    tot_exam2 += students[i].Marks[m][l];
                }
                if (m == 2) {
                    tot_exam3 += students[i].Marks[m][l];
                }
                if (l == 0) {
                    tot_sub1 += students[i].Marks[m][l];
                }
                if (l == 1) {
                    tot_sub2 += students[i].Marks[m][l];
                }
                if (l == 2) {
                    tot_sub3 += students[i].Marks[m][l];
                }
            }
        }

        total = tot_exam1 + tot_exam2 + tot_exam3;

        students[i].exam1_tot = tot_exam1;
        students[i].exam2_tot = tot_exam2;
        students[i].exam3_tot = tot_exam3;
        students[i].sub1_tot = tot_sub1;
        students[i].sub2_tot = tot_sub2;
        students[i].sub3_tot = tot_sub3;
        students[i].total = total;

        // Grade calculation
        // Modify this part based on your grading criteria
        if (total >= 810 && total <= 900) {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'S';
        } else if (total >= 720 && total < 810) {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'A';
        } else if (total >= 630 && total < 720) {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'B';
        } else if (total >= 540 && total < 630) {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'C';
        } else if (total >= 450 && total < 540) {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'D';
        } else {
            students[i].exam1_grade = students[i].exam2_grade = students[i].exam3_grade = students[i].sub1_grade =
                students[i].sub2_grade = students[i].sub3_grade = 'F';
        }
    }

    FILE *fp = fopen("STUDENT.DAT", "wb");
    if (fp == NULL) {
        printf("Error in opening the file \n");
        exit(1);
    }

    fwrite(students, sizeof(struct Student), n, fp);

    fclose(fp);
    return 0;
}

int searchAndDisplayStudent() {
    char search_srn[MAX_SRN_LENGTH + 1];
    printf("Enter the SRN of the student you want to find: ");
    scanf("%6s", search_srn);

    FILE *fp = fopen("STUDENT.DAT", "rb");
    if (fp == NULL) {
        printf("Error in opening the file \n");
        exit(1);
    }

    struct Student student;
    int found = 0;
    while (fread(&student, sizeof(struct Student), 1, fp)) {
        if (strcmp(student.srn, search_srn) == 0) {
            displayStudentDetails(&student);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf("Student with SRN %s not found\n", search_srn);
    }
    return 0;
}
