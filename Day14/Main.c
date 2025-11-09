#include <stdio.h>

int main() 
{
    int totalCustomers, roomType, days;
    char name[50];
    char breakfast, wifi, gym;
    int i = 1;

    float rate, baseFare, serviceCharge, subtotal, discount, gst, finalBill;
    float totalRevenue = 0, highestBill = 0, lowestBill = 0;
    int totalRooms = 0;

    printf("========= Smart Hotel Room Booking System =========\n");
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);

    while (i <= totalCustomers) {
        printf("\n--- Customer %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
        scanf("%d", &roomType);

        if (roomType == 1)
            rate = 2500;
        else if (roomType == 2)
            rate = 4000;
        else if (roomType == 3)
            rate = 6000;
        else {
            printf("Invalid room type! Skipping customer.\n");
            i++;
            continue;
        }

        printf("Enter number of days: ");
        scanf("%d", &days);

        printf("Breakfast (Y/N): ");
        scanf(" %c", &breakfast);
        printf("Wi-Fi (Y/N): ");
        scanf(" %c", &wifi);
        printf("Gym Access (Y/N): ");
        scanf(" %c", &gym);
      
        baseFare = rate * days;

        serviceCharge = 0;
        if (breakfast == 'Y' || breakfast == 'y')
            serviceCharge += 300 * days;
        if (wifi == 'Y' || wifi == 'y')
            serviceCharge += 100 * days;
        if (gym == 'Y' || gym == 'y')
            serviceCharge += 200 * days;

        subtotal = baseFare + serviceCharge;

        if (subtotal > 10000)
            discount = subtotal * 0.10;
        else
            discount = 0;

        gst = (subtotal - discount) * 0.12;

        finalBill = subtotal - discount + gst;

        printf("Base Fare: ₹%.0f\n", baseFare);
        printf("Additional Services: ₹%.0f\n", serviceCharge);
        printf("Subtotal: ₹%.0f\n", subtotal);
        printf("Discount: ₹%.0f\n", discount);
        printf("GST (12%%): ₹%.0f\n", gst);
        printf("Final Bill: ₹%.0f\n", finalBill);

        totalRevenue += finalBill;
        totalRooms++;

        if (i == 1) {
            highestBill = finalBill;
            lowestBill = finalBill;
        } else {
            if (finalBill > highestBill)
                highestBill = finalBill;
            if (finalBill < lowestBill)
                lowestBill = finalBill;
        }

        i++;
    }

    printf("\n========= Hotel Summary =========\n");
    printf("Total Rooms Booked: %d\n", totalRooms);
    printf("Total Revenue: ₹%.0f\n", totalRevenue);
    printf("Highest Bill: ₹%.0f\n", highestBill);
    printf("Lowest Bill: ₹%.0f\n", lowestBill);
    printf("=================================\n");

    return 0;
}
