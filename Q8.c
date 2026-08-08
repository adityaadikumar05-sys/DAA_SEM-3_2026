/**8. Student Result Analysis
• Store the roll number, name, and marks in five subjects for N students using structures.
• Calculate the total, percentage, and grade of each student.
• Display the class topper, students who failed in one or more subjects, and the class average */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    int rollNumber;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

void calculateResult(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = (float)s->total / 5.0;

    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 80) s->grade = 'B';
    else if (s->percentage >= 70) s->grade = 'C';
    else if (s->percentage >= 60) s->grade = 'D';
    else s->grade = 'F';
}

void displayStudent(struct Student s) {
    printf("Roll: %d, Name: %s, Total: %d, Percentage: %.2f, Grade: %c\n",
           s.rollNumber, s.name, s.total, s.percentage, s.grade);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS) {
        printf("Maximum students allowed is %d\n", MAX_STUDENTS);
        return 1;
    }

    struct Student students[n];
    int classTotal = 0;
    int topperIndex = -1;
    float maxPercentage = -1.0;

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Enter marks in 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
        calculateResult(&students[i]);
        classTotal += students[i].total;

        if (students[i].percentage > maxPercentage) {
            maxPercentage = students[i].percentage;
            topperIndex = i;
        }
    }

    printf("\n--- Student Results ---\n");
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    printf("\n--- Class Topper ---\n");
    if (topperIndex != -1) {
        displayStudent(students[topperIndex]);
    }

    printf("\n--- Students Who Failed ---\n");
    for (int i = 0; i < n; i++) {
        int failed = 0;
        for (int j = 0; j < 5; j++) {
            if (students[i].marks[j] < 40) { // Assuming 40 is the passing mark
                failed = 1;
                break;
            }
        }
        if (failed || students[i].grade == 'F') {
            displayStudent(students[i]);
        }
    }

    float classAverage = (float)classTotal / (n * 5);
    printf("\nClass Average Percentage: %.2f\n", classAverage);

    return 0;
}
