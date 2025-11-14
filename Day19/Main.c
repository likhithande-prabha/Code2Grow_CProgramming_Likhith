#include <stdio.h>

int main() {

    int attendance[5][5];
    int marks[5][5];
    char names[5][20];

    int i, j;

    // ---------------- INPUT PHASE -----------------

    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nEnter Attendance Matrix (1 = Present, 0 = Absent):\n");
    for(i = 0; i < 5; i++) {
        printf("Attendance for %s:\n", names[i]);
        for(j = 0; j < 5; j++) {
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nEnter Marks Matrix (0–100):\n");
    for(i = 0; i < 5; i++) {
        printf("Marks for %s:\n", names[i]);
        for(j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // ------------------- MENU SYSTEM -------------------

    int choice = 0;
    while(choice != 6) {

        printf("\n========= MENU =========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // ---------------- OPTION 1: Display Attendance Matrix ----------------
        if(choice == 1) {
            printf("\nAttendance Matrix:\n");
            for(i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for(j = 0; j < 5; j++) {
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        }

        // ---------------- OPTION 2: Display Marks Matrix ----------------
        else if(choice == 2) {
            printf("\nMarks Matrix:\n");
            for(i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for(j = 0; j < 5; j++) {
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        }

        // ---------------- OPTION 3: Attendance Report ----------------
        else if(choice == 3) {

            int totalPresent[5], totalAbsent[5];
            int highest = -1, lowest = 6;
            int highIndex = 0, lowIndex = 0;

            for(i = 0; i < 5; i++) {
                totalPresent[i] = 0;
                totalAbsent[i] = 0;

                for(j = 0; j < 5; j++) {
                    if(attendance[i][j] == 1)
                        totalPresent[i]++;
                    else
                        totalAbsent[i]++;
                }

                if(totalPresent[i] > highest) {
                    highest = totalPresent[i];
                    highIndex = i;
                }
                if(totalPresent[i] < lowest) {
                    lowest = totalPresent[i];
                    lowIndex = i;
                }
            }

            printf("\n===== Attendance Report =====\n");
            for(i = 0; i < 5; i++) {
                printf("%s - Present: %d | Absent: %d\n",
                       names[i], totalPresent[i], totalAbsent[i]);
            }

            printf("\nHighest Attendance: %s (%d days)\n", names[highIndex], highest);
            printf("Lowest Attendance: %s (%d days)\n", names[lowIndex], lowest);
        }

        // ---------------- OPTION 4: Performance Report ----------------
        else if(choice == 4) {

            int totalMarks[5];
            float avg[5];
            int topper = 0, lowper = 0;

            for(i = 0; i < 5; i++) {
                totalMarks[i] = 0;

                for(j = 0; j < 5; j++) {
                    totalMarks[i] += marks[i][j];
                }

                avg[i] = totalMarks[i] / 5.0;
            }

            for(i = 1; i < 5; i++) {
                if(totalMarks[i] > totalMarks[topper])
                    topper = i;
                if(totalMarks[i] < totalMarks[lowper])
                    lowper = i;
            }

            printf("\n===== Performance Report =====\n");
            for(i = 0; i < 5; i++) {
                printf("%s - Total: %d | Average: %.2f\n", names[i], totalMarks[i], avg[i]);
            }

            printf("\nClass Topper: %s (%d marks)\n", names[topper], totalMarks[topper]);
            printf("Lowest Performer: %s (%d marks)\n", names[lowper], totalMarks[lowper]);
        }

        // ---------------- OPTION 5: Grade Report ----------------
        else if(choice == 5) {

            float avg[5];
            int totalMarks[5];

            for(i = 0; i < 5; i++) {
                totalMarks[i] = 0;
                for(j = 0; j < 5; j++)
                    totalMarks[i] += marks[i][j];

                avg[i] = totalMarks[i] / 5.0;
            }

            printf("\n===== Grade Report =====\n");
            for(i = 0; i < 5; i++) {

                char grade;

                if(avg[i] >= 90) grade = 'A'+('+');
                char gradeStr[3];

                if(avg[i] >= 90) sprintf(gradeStr, "A+");
                else if(avg[i] >= 80) sprintf(gradeStr, "A");
                else if(avg[i] >= 70) sprintf(gradeStr, "B");
                else if(avg[i] >= 60) sprintf(gradeStr, "C");
                else if(avg[i] >= 50) sprintf(gradeStr, "D");
                else sprintf(gradeStr, "F");

                printf("%s - Average: %.2f | Grade: %s\n", names[i], avg[i], gradeStr);
            }
        }

        else if(choice == 6) {
            printf("\nExiting program...\n");
        }

        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
