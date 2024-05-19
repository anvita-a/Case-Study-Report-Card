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
    printf("Total grade for semester: %c\n", student->tot_grade);
    printf("\n");
}

int Entry(struct Student **students, int *n) {
    printf("Enter the number of students: ");
    scanf("%d", n);
    scanf("%*c");

    *students = (struct Student *)malloc(*n * sizeof(struct Student));
    if (*students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        printf("SRN: ");
        scanf("%6s", (*students)[i].srn);
        scanf("%*c");

        printf("NAME: ");
        scanf("%67[^\n]", (*students)[i].name);
        scanf("%*c");

        printf("SEMESTER: ");
        scanf("%d", &(*students)[i].sem);
        scanf("%*c");

        while ((*students)[i].sem < 1 || (*students)[i].sem > 10) {
            printf("The semester number is wrong. Enter the correct semester number: ");
            scanf("%d", &(*students)[i].sem);
            scanf("%*c");
        }

        printf("SECTION: ");
        scanf("%c", &(*students)[i].sec);
        scanf("%*c");

        printf("MARKS:\n");
        for (int k = 0; k < MAX_EXAMS; k++) {
            printf("Enter the marks for ISA%d: \n", k + 1);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("Enter the marks for subject%d out of 100: ", j + 1);
                scanf("%f", &(*students)[i].Marks[k][j]);
            }
            printf("\n");
        }

        float tot_exam1 = 0, tot_exam2 = 0, tot_exam3 = 0, tot_sub1 = 0, tot_sub2 = 0, tot_sub3 = 0, total = 0;

        for (int m = 0; m < MAX_EXAMS; m++) {
            for (int l = 0; l < MAX_SUBJECTS; l++) {
                if (m == 0) {
                    tot_exam1 += (*students)[i].Marks[m][l];
                }
                if (m == 1) {
                    tot_exam2 += (*students)[i].Marks[m][l];
                }
                if (m == 2) {
                    tot_exam3 += (*students)[i].Marks[m][l];
                }
                if (l == 0) {
                    tot_sub1 += (*students)[i].Marks[m][l];
                }
                if (l == 1) {
                    tot_sub2 += (*students)[i].Marks[m][l];
                }
                if (l == 2) {
                    tot_sub3 += (*students)[i].Marks[m][l];
                }
            }
        }

        total = tot_exam1 + tot_exam2 + tot_exam3;

        (*students)[i].exam1_tot = tot_exam1;
        (*students)[i].exam2_tot = tot_exam2;
        (*students)[i].exam3_tot = tot_exam3;
        (*students)[i].sub1_tot = tot_sub1;
        (*students)[i].sub2_tot = tot_sub2;
        (*students)[i].sub3_tot = tot_sub3;
        (*students)[i].total = total;

        if (tot_exam1 >= 270 && tot_exam1 <= 300) {
            (*students)[i].exam1_grade = 'S';
        } else if (tot_exam1 >= 240 && tot_exam1 < 270) {
            (*students)[i].exam1_grade = 'A';
        } else if (tot_exam1 >= 210 && tot_exam1 < 240) {
            (*students)[i].exam1_grade = 'B';
        } else if (tot_exam1 >= 180 && tot_exam1 < 210) {
            (*students)[i].exam1_grade = 'C';
        } else if (tot_exam1 >= 150 && tot_exam1 < 180) {
           (*students)[i].exam1_grade = 'D';
        } else {
            (*students)[i].exam1_grade = 'F';
        }




        if (tot_exam2 >= 270 && tot_exam2 <= 300) {
            (*students)[i].exam2_grade = 'S';
        } else if (tot_exam2 >= 240 && tot_exam2 < 270) {
            (*students)[i].exam2_grade = 'A';
        } else if (tot_exam2 >= 210 && tot_exam2 < 240) {
            (*students)[i].exam2_grade = 'B';
        } else if (tot_exam2 >= 180 && tot_exam2 < 210) {
            (*students)[i].exam2_grade = 'C';
        } else if (tot_exam2 >= 150 && tot_exam2 < 180) {
           (*students)[i].exam2_grade = 'D';
        } else {
            (*students)[i].exam2_grade = 'F';
        }




        if (tot_exam3 >= 270 && tot_exam3 <= 300) {
            (*students)[i].exam3_grade = 'S';
        } else if (tot_exam3 >= 240 && tot_exam3 < 270) {
            (*students)[i].exam3_grade = 'A';
        } else if (tot_exam3 >= 210 && tot_exam3 < 240) {
            (*students)[i].exam3_grade = 'B';
        } else if (tot_exam3 >= 180 && tot_exam3 < 210) {
            (*students)[i].exam3_grade = 'C';
        } else if (tot_exam3 >= 150 && tot_exam3 < 180) {
           (*students)[i].exam3_grade = 'D';
        } else {
            (*students)[i].exam3_grade = 'F';
        }




        if (tot_sub1 >= 270 && tot_sub1 <= 300) {
            (*students)[i].sub1_grade = 'S';
        } else if (tot_sub1 >= 240 && tot_sub1 < 270) {
            (*students)[i].sub1_grade = 'A';
        } else if (tot_sub1 >= 210 && tot_sub1 < 240) {
            (*students)[i].sub1_grade = 'B';
        } else if (tot_sub1 >= 180 && tot_sub1 < 210) {
            (*students)[i].sub1_grade = 'C';
        } else if (tot_sub1 >= 150 && tot_sub1 < 180) {
           (*students)[i].sub1_grade = 'D';
        } else {
            (*students)[i].sub1_grade = 'F';
        }




        if (tot_sub2 >= 270 && tot_sub2 <= 300) {
            (*students)[i].sub2_grade = 'S';
        } else if (tot_sub2 >= 240 && tot_sub2 < 270) {
            (*students)[i].sub2_grade = 'A';
        } else if (tot_sub2 >= 210 && tot_sub2 < 240) {
            (*students)[i].sub2_grade = 'B';
        } else if (tot_sub2 >= 180 && tot_sub2 < 210) {
            (*students)[i].sub2_grade = 'C';
        } else if (tot_sub2 >= 150 && tot_sub2 < 180) {
           (*students)[i].sub2_grade = 'D';
        } else {
            (*students)[i].sub2_grade = 'F';
        }





        if (tot_sub3 >= 270 && tot_sub3 <= 300) {
            (*students)[i].sub3_grade = 'S';
        } else if (tot_sub3 >= 240 && tot_sub3 < 270) {
            (*students)[i].sub3_grade = 'A';
        } else if (tot_sub3 >= 210 && tot_sub3 < 240) {
            (*students)[i].sub3_grade = 'B';
        } else if (tot_sub3 >= 180 && tot_sub3 < 210) {
            (*students)[i].sub3_grade = 'C';
        } else if (tot_sub3 >= 150 && tot_sub3 < 180) {
           (*students)[i].sub3_grade = 'D';
        } else {
            (*students)[i].sub3_grade = 'F';
        }




        if (total >= 810 && total <= 900) {
            (*students)[i].tot_grade = 'S';
        } else if (total >= 720 && total < 810) {
            (*students)[i].tot_grade = 'A';
        } else if (total >= 630 && total < 720) {
            (*students)[i].tot_grade = 'B';
        } else if (total >= 540 && total < 630) {
            (*students)[i].tot_grade = 'C';
        } else if (total >= 450 && total < 540) {
           (*students)[i].tot_grade = 'D';
        } else {
            (*students)[i].tot_grade = 'F';
        }




    }






    FILE *fp = fopen("STUDENT.DAT", "wb");
    if (fp == NULL) {
        printf("Error in opening the file \n");
        free(*students);
        exit(1);
    }

    fwrite(*students, sizeof(struct Student), *n, fp);
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

int insertStudent(struct Student **students, int *n) {
    *students = (struct Student *)realloc(*students, (*n + 1) * sizeof(struct Student));
    if (*students == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("Enter details for the new student:\n");
    int i = *n;

    printf("SRN: ");
    scanf("%6s", (*students)[i].srn);
    scanf("%*c");

    printf("NAME: ");
    scanf("%67[^\n]", (*students)[i].name);
    scanf("%*c");

    printf("SEMESTER: ");
    scanf("%d", &(*students)[i].sem);
    scanf("%*c");

    while ((*students)[i].sem < 1 || (*students)[i].sem > 10) {
        printf("The semester number is wrong. Enter the correct semester number: ");
        scanf("%d", &(*students)[i].sem);
        scanf("%*c");
    }

    printf("SECTION: ");
    scanf("%c", &(*students)[i].sec);
    scanf("%*c");

    printf("MARKS:\n");
    for (int k = 0; k < MAX_EXAMS; k++) {
        printf("Enter the marks for ISA%d: \n", k + 1);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Enter the marks for subject%d out of 100: ", j + 1);
            scanf("%f", &(*students)[i].Marks[k][j]);
        }
        printf("\n");
    }

    float tot_exam1 = 0, tot_exam2 = 0, tot_exam3 = 0, tot_sub1 = 0, tot_sub2 = 0, tot_sub3 = 0, total = 0;

    for (int m = 0; m < MAX_EXAMS; m++) {
        for (int l = 0; l < MAX_SUBJECTS; l++) {
            if (m == 0) {
                tot_exam1 += (*students)[i].Marks[m][l];
            }
            if (m == 1) {
                tot_exam2 += (*students)[i].Marks[m][l];
            }
            if (m == 2) {
                tot_exam3 += (*students)[i].Marks[m][l];
            }
            if (l == 0) {
                tot_sub1 += (*students)[i].Marks[m][l];
            }
            if (l == 1) {
                tot_sub2 += (*students)[i].Marks[m][l];
            }
            if (l == 2) {
                tot_sub3 += (*students)[i].Marks[m][l];
            }
        }
    }

    total = tot_exam1 + tot_exam2 + tot_exam3;

    (*students)[i].exam1_tot = tot_exam1;
    (*students)[i].exam2_tot = tot_exam2;
    (*students)[i].exam3_tot = tot_exam3;
    (*students)[i].sub1_tot = tot_sub1;
    (*students)[i].sub2_tot = tot_sub2;
    (*students)[i].sub3_tot = tot_sub3;
    (*students)[i].total = total;

            if (tot_exam1 >= 270 && tot_exam1 <= 300) {
            (*students)[i].exam1_grade = 'S';
        } else if (tot_exam1 >= 240 && tot_exam1 < 270) {
            (*students)[i].exam1_grade = 'A';
        } else if (tot_exam1 >= 210 && tot_exam1 < 240) {
            (*students)[i].exam1_grade = 'B';
        } else if (tot_exam1 >= 180 && tot_exam1 < 210) {
            (*students)[i].exam1_grade = 'C';
        } else if (tot_exam1 >= 150 && tot_exam1 < 180) {
           (*students)[i].exam1_grade = 'D';
        } else {
            (*students)[i].exam1_grade = 'F';
        }




        if (tot_exam2 >= 270 && tot_exam2 <= 300) {
            (*students)[i].exam2_grade = 'S';
        } else if (tot_exam2 >= 240 && tot_exam2 < 270) {
            (*students)[i].exam2_grade = 'A';
        } else if (tot_exam2 >= 210 && tot_exam2 < 240) {
            (*students)[i].exam2_grade = 'B';
        } else if (tot_exam2 >= 180 && tot_exam2 < 210) {
            (*students)[i].exam2_grade = 'C';
        } else if (tot_exam2 >= 150 && tot_exam2 < 180) {
           (*students)[i].exam2_grade = 'D';
        } else {
            (*students)[i].exam2_grade = 'F';
        }




        if (tot_exam3 >= 270 && tot_exam3 <= 300) {
            (*students)[i].exam3_grade = 'S';
        } else if (tot_exam3 >= 240 && tot_exam3 < 270) {
            (*students)[i].exam3_grade = 'A';
        } else if (tot_exam3 >= 210 && tot_exam3 < 240) {
            (*students)[i].exam3_grade = 'B';
        } else if (tot_exam3 >= 180 && tot_exam3 < 210) {
            (*students)[i].exam3_grade = 'C';
        } else if (tot_exam3 >= 150 && tot_exam3 < 180) {
           (*students)[i].exam3_grade = 'D';
        } else {
            (*students)[i].exam3_grade = 'F';
        }




        if (tot_sub1 >= 270 && tot_sub1 <= 300) {
            (*students)[i].sub1_grade = 'S';
        } else if (tot_sub1 >= 240 && tot_sub1 < 270) {
            (*students)[i].sub1_grade = 'A';
        } else if (tot_sub1 >= 210 && tot_sub1 < 240) {
            (*students)[i].sub1_grade = 'B';
        } else if (tot_sub1 >= 180 && tot_sub1 < 210) {
            (*students)[i].sub1_grade = 'C';
        } else if (tot_sub1 >= 150 && tot_sub1 < 180) {
           (*students)[i].sub1_grade = 'D';
        } else {
            (*students)[i].sub1_grade = 'F';
        }




        if (tot_sub2 >= 270 && tot_sub2 <= 300) {
            (*students)[i].sub2_grade = 'S';
        } else if (tot_sub2 >= 240 && tot_sub2 < 270) {
            (*students)[i].sub2_grade = 'A';
        } else if (tot_sub2 >= 210 && tot_sub2 < 240) {
            (*students)[i].sub2_grade = 'B';
        } else if (tot_sub2 >= 180 && tot_sub2 < 210) {
            (*students)[i].sub2_grade = 'C';
        } else if (tot_sub2 >= 150 && tot_sub2 < 180) {
           (*students)[i].sub2_grade = 'D';
        } else {
            (*students)[i].sub2_grade = 'F';
        }





        if (tot_sub3 >= 270 && tot_sub3 <= 300) {
            (*students)[i].sub3_grade = 'S';
        } else if (tot_sub3 >= 240 && tot_sub3 < 270) {
            (*students)[i].sub3_grade = 'A';
        } else if (tot_sub3 >= 210 && tot_sub3 < 240) {
            (*students)[i].sub3_grade = 'B';
        } else if (tot_sub3 >= 180 && tot_sub3 < 210) {
            (*students)[i].sub3_grade = 'C';
        } else if (tot_sub3 >= 150 && tot_sub3 < 180) {
           (*students)[i].sub3_grade = 'D';
        } else {
            (*students)[i].sub3_grade = 'F';
        }




        if (total >= 810 && total <= 900) {
            (*students)[i].tot_grade = 'S';
        } else if (total >= 720 && total < 810) {
            (*students)[i].tot_grade = 'A';
        } else if (total >= 630 && total < 720) {
            (*students)[i].tot_grade = 'B';
        } else if (total >= 540 && total < 630) {
            (*students)[i].tot_grade = 'C';
        } else if (total >= 450 && total < 540) {
           (*students)[i].tot_grade = 'D';
        } else {
            (*students)[i].tot_grade = 'F';
        }

    (*n)++;
    FILE *fp = fopen("STUDENT.DAT", "wb");
    if (fp == NULL) {
        printf("Error in opening the file \n");
        free(*students);
        exit(1);
    }

    fwrite(*students, sizeof(struct Student), *n, fp);
    fclose(fp);
    return 0;
}

int deleteStudent(struct Student **students, int *n) {
    char delete_srn[MAX_SRN_LENGTH + 1];
    printf("Enter the SRN of the student you want to delete: ");
    scanf("%6s", delete_srn);

    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp((*students)[i].srn, delete_srn) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with SRN %s not found\n", delete_srn);
        return 1;
    }

    for (int i = index; i < *n - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    (*n)--;
    *students = (struct Student *)realloc(*students, *n * sizeof(struct Student));
    if (*students == NULL && *n > 0) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    FILE *fp = fopen("STUDENT.DAT", "wb");
    if (fp == NULL) {
        printf("Error in opening the file \n");
        free(*students);
        exit(1);
    }

    fwrite(*students, sizeof(struct Student), *n, fp);
    fclose(fp);
    return 0;
}
