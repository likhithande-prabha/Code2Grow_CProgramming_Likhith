#include <stdio.h>

int main() {
    int n, i;
    int marks[10];
    int total = 0, highest, lowest;
    int pass = 0, fail = 0;
    int gradeAplus = 0, gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0;

    printf("========= Student Performance Analyzer =========\n");
    printf("Enter total number of students (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of students! Please enter between 1 and 10.\n");
        return 0;
    }

    printf("Enter marks for each student:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];

        if (marks[i] >= 90)
            gradeAplus++;
        else if (marks[i] >= 80)
            gradeA++;
        else if (marks[i] >= 70)
            gradeB++;
        else if (marks[i] >= 60)
            gradeC++;
        else if (marks[i] >= 50)
            gradeD++;
        else
            fail++;

        if (marks[i] >= 50)
            pass++;
    }

    highest = lowest = marks[0];
    for (i = 1; i < n; i++) {
        if (marks[i] > highest)
            highest = marks[i];
        if (marks[i] < lowest)
            lowest = marks[i];
    }

    float average = (float)total / n;

    printf("========= Result Summary =========\n");
    printf("Average Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Total Passed Students: %d\n", pass);
    printf("Total Failed Students: %d\n", fail);
    printf("Grade Distribution:\n");
    printf("A+ : %d\n", gradeAplus);
    printf("A  : %d\n", gradeA);
    printf("B  : %d\n", gradeB);
    printf("C  : %d\n", gradeC);
    printf("D  : %d\n", gradeD);
    printf("Fail: %d\n", fail);
    printf("==================================\n");

    return 0;
}
