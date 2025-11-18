#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Function declarations
void inputData(int vehicleID[], int speed[], int lane[], int *n);
int countSpeedViolations(int speed[], int n, int *highest, int *lowest);
int countLaneViolations(int vehicleID[], int lane[], int n, int *severeVeh, int *maxSeverity);
int busiestLane(int laneCount[]);
int leastBusyLane(int laneCount[]);
void displayReport(int vehicleID[], int speed[], int lane[], int n);

int main() {

    int vehicleID[MAX], speed[MAX], lane[MAX];
    int n;

    // 1. Input data
    inputData(vehicleID, speed, lane, &n);

    // Variables for detection
    int highest, lowest;
    int overspeedCount = countSpeedViolations(speed, n, &highest, &lowest);

    int severeVeh, maxSeverity;
    int laneViolationCount = countLaneViolations(vehicleID, lane, n, &severeVeh, &maxSeverity);

    // Traffic density array
    int laneCount[4] = {0};
    for(int i = 0; i < n; i++) {
        laneCount[lane[i] - 1]++;  // lane 1→index 0
    }

    int busiest = busiestLane(laneCount);
    int least = leastBusyLane(laneCount);

    // Display report
    displayReport(vehicleID, speed, lane, n);

    // Summary Output
    printf("\n===== TRAFFIC SUMMARY =====\n");
    printf("Total Overspeeding Vehicles: %d\n", overspeedCount);
    printf("Highest Speed Recorded: %d\n", highest);
    printf("Lowest Speed Recorded: %d\n", lowest);
    printf("Lane Violation Count: %d\n", laneViolationCount);
    printf("Most Severe Violation Vehicle ID: %d (Severity = %d)\n", severeVeh, maxSeverity);
    printf("Busiest Lane: %d\n", busiest);
    printf("Least Busy Lane: %d\n", least);
    printf("Total Traffic Volume: %d\n", n);

    return 0;
}

// -------------------------------------------------------------

void inputData(int vehicleID[], int speed[], int lane[], int *n) {
    printf("Enter number of vehicles (max 30): ");
    scanf("%d", n);

    if (*n > MAX) {
        printf("Exceeded maximum limit! Setting n = 30.\n");
        *n = MAX;
    }

    for(int i = 0; i < *n; i++) {
        printf("\nVehicle %d:\n", i+1);

        printf("Vehicle ID (4-digit): ");
        scanf("%d", &vehicleID[i]);

        do {
            printf("Speed (km/h): ");
            scanf("%d", &speed[i]);
        } while(speed[i] <= 0);

        do {
            printf("Lane (1–4): ");
            scanf("%d", &lane[i]);
        } while(lane[i] < 1 || lane[i] > 4);
    }
}

// -------------------------------------------------------------

int countSpeedViolations(int speed[], int n, int *highest, int *lowest) {

    int count = 0;
    *highest = speed[0];
    *lowest = speed[0];

    for(int i = 0; i < n; i++) {

        if (speed[i] > 80)
            count++;

        if (speed[i] > *highest)
            *highest = speed[i];

        if (speed[i] < *lowest)
            *lowest = speed[i];
    }
    return count;
}

// -------------------------------------------------------------

int countLaneViolations(int vehicleID[], int lane[], int n, int *severeVeh, int *maxSeverity) {

    int count = 0;
    *maxSeverity = 0;

    for(int i = 0; i < n; i++) {

        int expected = vehicleID[i] % 4;
        if (expected == 0) expected = 4; // Handle remainder 0 meaning lane 4

        if (expected != lane[i]) {
            count++;

            int severity = abs(expected - lane[i]);

            if (severity > *maxSeverity) {
                *maxSeverity = severity;
                *severeVeh = vehicleID[i];
            }
        }
    }
    return count;
}

// -------------------------------------------------------------

int busiestLane(int laneCount[]) {
    int max = laneCount[0], lane = 1;

    for(int i = 1; i < 4; i++) {
        if(laneCount[i] > max) {
            max = laneCount[i];
            lane = i+1;
        }
    }
    return lane;
}

int leastBusyLane(int laneCount[]) {
    int min = laneCount[0], lane = 1;

    for(int i = 1; i < 4; i++) {
        if(laneCount[i] < min) {
            min = laneCount[i];
            lane = i+1;
        }
    }
    return lane;
}

// -------------------------------------------------------------

void displayReport(int vehicleID[], int speed[], int lane[], int n) {

    printf("\n================ TRAFFIC REPORT ================\n");
    printf("VehID\tSpeed\tLane\tSpeedVio\tLaneVio\n");

    for(int i = 0; i < n; i++) {

        int speedVio = (speed[i] > 80) ? 1 : 0;

        int expected = vehicleID[i] % 4;
        if (expected == 0) expected = 4;

        int laneVio = (expected != lane[i]) ? 1 : 0;

        printf("%d\t%d\t%d\t%d\t\t%d\n",
               vehicleID[i], speed[i], lane[i], speedVio, laneVio);
    }
}
