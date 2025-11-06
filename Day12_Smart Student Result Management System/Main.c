#include <stdio.h>

int main() {
    int num_students;
    int student_count = 1;
    float mark1, mark2, mark3;
    float avg, total;
    int choice;
    int passed = 0, failed = 0;
    float class_total = 0;
    float highest_avg = 0, lowest_avg = 100;
    int current_student = 1;

    printf("Smart Student Result Management\n");
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // Store results temporarily using variables (no arrays)
    float avg1, avg2, avg3;
    char grade1, grade2, grade3;

    while (student_count <= num_students) {
        printf("--- Student %d ---\n", student_count);
        printf("Enter marks for Subject 1: ");
        scanf("%f", &mark1);
        printf("Enter marks for Subject 2: ");
        scanf("%f", &mark2);
        printf("Enter marks for Subject 3: ");
        scanf("%f", &mark3);

        total = mark1 + mark2 + mark3;
        avg = total / 3.0;
        class_total += avg;

        if (avg > highest_avg) highest_avg = avg;
        if (avg < lowest_avg) lowest_avg = avg;

        if (avg >= 90)
            printf("Grade: A+\n");
        else if (avg >= 80)
            printf("Grade: A\n");
        else if (avg >= 70)
            printf("Grade: B\n");
        else if (avg >= 60)
            printf("Grade: C\n");
        else if (avg >= 50)
            printf("Grade: D\n");
        else
            printf("Grade: Fail\n");

        if (avg >= 50)
            passed++;
        else
            failed++;

        // Store individual averages and grades manually
        if (student_count == 1) avg1 = avg;
        if (student_count == 2) avg2 = avg;
        if (student_count == 3) avg3 = avg;

        student_count++;
    }

    do {
        printf("========= Menu =========\n");
        printf("1. View All Results\n");
        printf("2. View Class Summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("--- Result Sheet ---\n");
            if (num_students >= 1)
                printf("Student 1: Avg = %.1f\n", avg1);
            if (num_students >= 2)
                printf("Student 2: Avg = %.1f\n", avg2);
            if (num_students >= 3)
                printf("Student 3: Avg = %.1f\n", avg3);
        } else if (choice == 2) {
            printf("--- Class Summary ---\n");
            printf("Total Students: %d\n", num_students);
            printf("Passed: %d\n", passed);
            printf("Failed: %d\n", failed);
            printf("Class Average: %.1f\n", class_total / num_students);
            printf("Highest Average: %.1f\n", highest_avg);
            printf("Lowest Average: %.1f\n", lowest_avg);
        } else if (choice == 3) {
            printf("Thank you! Exiting system...\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}


