#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60}; // Fixed prices for 5 items
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int quantitySold[5] = {0}; // Tracks total quantity sold for each item

    int numCustomers, numItems, itemNo, qty;
    int i, j;
    float totalRevenue = 0;
    int totalItemsSold = 0;

    printf("========= Café Order Management System =========\n");
    printf("Menu:\n");
    printf("Item No.\tItem Name\tPrice (₹)\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t\t%s\t\t₹%d\n", i + 1, items[i], prices[i]);
    }

    printf("\nEnter total number of customers (max 10): ");
    scanf("%d", &numCustomers);

    for (i = 1; i <= numCustomers; i++) {
        float customerBill = 0;
        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        printf("Enter item number and quantity:\n");
        for (j = 0; j < numItems; j++) {
            scanf("%d %d", &itemNo, &qty);

            if (itemNo >= 1 && itemNo <= 5) {
                customerBill += prices[itemNo - 1] * qty;
                quantitySold[itemNo - 1] += qty;
                totalItemsSold += qty;
            } else {
                printf("Invalid item number! Skipping...\n");
            }
        }

        printf("Total Bill for Customer %d: ₹%.2f\n", i, customerBill);
        totalRevenue += customerBill;
    }

    // Find most and least ordered items
    int mostOrdered = 0, leastOrdered = 0;
    for (i = 1; i < 5; i++) {
        if (quantitySold[i] > quantitySold[mostOrdered])
            mostOrdered = i;
        if (quantitySold[i] < quantitySold[leastOrdered])
            leastOrdered = i;
    }

    printf("\n========= Café Summary =========\n");
    printf("Total Revenue: ₹%.2f\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", items[mostOrdered]);
    printf("Least Ordered Item: %s\n", items[leastOrdered]);
    printf("================================\n");

    return 0;
}
