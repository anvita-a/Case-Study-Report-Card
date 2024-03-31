#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SRN_LENGTH 10
#define MAX_NAME_LENGTH 100
#define MAX_EXAMS 3
#define MAX_SUBJECTS 3

struct Student {
    char srn[MAX_SRN_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1]; 
    int sem;
    char sec;
    float Marks[MAX_EXAMS][MAX_SUBJECTS];
    float exam1_tot, exam2_tot, exam3_tot;
    float sub1_tot, sub2_tot, sub3_tot;
    float total;
    char exam1_grade, exam2_grade, exam3_grade;
    char sub1_grade, sub2_grade, sub3_grade;
};

int Entry();
void displayStudentDetails(struct Student *student);
int searchAndDisplayStudent();

#endif /* STUDENT_H */
