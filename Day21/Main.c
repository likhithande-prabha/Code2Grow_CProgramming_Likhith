#include <stdio.h>
#include <stdlib.h>

void inputData(int vehicleID[], int speed[], int lane[], int n);
int countSpeedViolations(int speed[], int n, int *highest, int *lowest);
int countLaneViolations(int vehicleID[], int lane[], int n, int severity[]);
int busiestLane(int laneCount[]);
int leastBusyLane(int laneCount[]);
void displayReport(int vehicleID[], int speed[], int lane[], int speedViol[], int laneViol[], int n);

int main() {
    int n;
    int vehicleID[30], speed[30], lane[30];
    int speedViol[30] = {0}, laneViol[30] = {0};
    int severity[30] = {0};
    int highest, lowest;
    int laneCount[4] = {0};

    printf("Enter number of vehicles (max 30): ");
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("Invalid number of vehicles!\n");
        return 0;
    }

    inputData(vehicleID, speed, lane, n);

    int speedViolationCount = countSpeedViolations(speed, n, &highest, &lowest);

    int laneViolationCount = countLaneViolations(vehicleID, lane, n, severity);

    // Traffic Density
    for (int i = 0; i < n; i++) {
        laneCount[lane[i] - 1]++;
    }

    int busy = busiestLane(laneCount);
    int least = leastBusyLane(laneCount);

    // Identify Violations for Report
    for (int i = 0; i < n; i++) {
        if (speed[i] > 80) speedViol[i] = 1;
        if (severity[i] != 0) laneViol[i] = 1;
    }

    displayReport(vehicleID, speed, lane, speedViol, laneViol, n);

    printf("\n===== SUMMARY =====\n");
    printf("Total Speed Violations: %d\n", speedViolationCount);
    printf("Total Lane Violations: %d\n", laneViolationCount);
    printf("Highest Speed Recorded: %d km/h\n", highest);
    printf("Lowest Speed Recorded : %d km/h\n", lowest);

    printf("\nTraffic Density:\n");
    for (int i = 0; i < 4; i++) {
        printf("Lane %d Count: %d\n", i + 1, laneCount[i]);
    }
    printf("Busiest Lane: %d\n", busy);
    printf("Least Busy Lane: %d\n", least);
    printf("Total Traffic Volume: %d\n", n);

    return 0;
}

void inputData(int vehicleID[], int speed[], int lane[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nVehicle %d ID (4-digit): ", i + 1);
        scanf("%d", &vehicleID[i]);

        printf("Speed (km/h): ");
        scanf("%d", &speed[i]);

        while (speed[i] <= 0) {
            printf("Invalid! Speed must be positive. Enter again: ");
            scanf("%d", &speed[i]);
        }

        printf("Lane (1–4): ");
        scanf("%d", &lane[i]);

        while (lane[i] < 1 || lane[i] > 4) {
            printf("Invalid lane! Enter lane (1–4): ");
            scanf("%d", &lane[i]);
        }
    }
}

int countSpeedViolations(int speed[], int n, int *highest, int *lowest) {
    int count = 0;
    *highest = speed[0];
    *lowest = speed[0];

    for (int i = 0; i < n; i++) {
        if (speed[i] > 80) count++;

        if (speed[i] > *highest) *highest = speed[i];
        if (speed[i] < *lowest) *lowest = speed[i];
    }
    return count;
}

int countLaneViolations(int vehicleID[], int lane[], int n, int severity[]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int rule = vehicleID[i] % 4;
        if (rule == 0) rule = 4;

        severity[i] = abs(rule - lane[i]);
        if (severity[i] != 0) count++;
    }
    return count;
}

int busiestLane(int laneCount[]) {
    int max = laneCount[0], idx = 1;
    for (int i = 1; i < 4; i++) {
        if (laneCount[i] > max) {
            max = laneCount[i];
            idx = i + 1;
        }
    }
    return idx;
}

int leastBusyLane(int laneCount[]) {
    int min = laneCount[0], idx = 1;
    for (int i = 1; i < 4; i++) {
        if (laneCount[i] < min) {
            min = laneCount[i];
            idx = i + 1;
        }
    }
    return idx;
}

void displayReport(int vehicleID[], int speed[], int lane[], int speedViol[], int laneViol[], int n) {
    printf("\n=============================================================\n");
    printf("VehID\tSpeed\tLane\tSpeedViol\tLaneViol\n");
    printf("=============================================================\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\n",
            vehicleID[i],
            speed[i],
            lane[i],
            speedViol[i],
            laneViol[i]
        );
    }
}
