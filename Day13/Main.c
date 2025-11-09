#include <stdio.h>

int main() {
    int totalPassengers, age, time, i;
    float distance, fare, totalFare = 0, baseFare;
    float highestFare = 0, lowestFare = 99999;
    char name[30];

    printf("=========== SRM Smart Bus Fare Calculator ===========\n");
    printf("Enter number of passengers: ");
    scanf("%d", &totalPassengers);

    for (i = 1; i <= totalPassengers; i++) {
        printf("\n--- Passenger %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter distance (in km): ");
        scanf("%f", &distance);
        printf("Enter travel time (24-hour format): ");
        scanf("%d", &time);

        baseFare = distance * 10; // ₹10 per km
        fare = baseFare;

        if (age <= 12) {
            fare *= 0.5; // 50% off
            printf("Passenger: %s | Base Fare: ₹%.0f | Child Discount Applied | Final Fare: ₹%.0f\n",
                   name, baseFare, fare);
        }
        else if (age >= 60) {
            fare *= 0.7; // 30% off
            printf("Passenger: %s | Base Fare: ₹%.0f | Senior Citizen Discount Applied | Final Fare: ₹%.0f\n",
                   name, baseFare, fare);
        }
      
        else if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            fare *= 1.2; // +20% charge
            printf("Passenger: %s | Base Fare: ₹%.0f | Peak Hour Surcharge Applied | Final Fare: ₹%.0f\n",
                   name, baseFare, fare);
        } 
       
        else {
            printf("Passenger: %s | Base Fare: ₹%.0f | Final Fare: ₹%.0f\n",
                   name, baseFare, fare);
        }

        totalFare += fare;

        if (fare > highestFare)
            highestFare = fare;
        if (fare < lowestFare)
            lowestFare = fare;
    }

    printf("\n=========== Daily Summary ===========\n");
    printf("Total Passengers: %d\n", totalPassengers);
    printf("Total Revenue Collected: ₹%.0f\n", totalFare);
    printf("Highest Fare: ₹%.0f\n", highestFare);
    printf("Lowest Fare: ₹%.0f\n", lowestFare);

    return 0;
}
