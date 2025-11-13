#include <stdio.h>

int main() {
    int productID[10];
    char productName[10][50];
    int quantity[10];
    float price[10];
    int n = 0;  

    int choice, i;
    float totalValue, highestValue, lowestValue;
    int highestIndex, lowestIndex;
    int searchID, found;

    while (1) {
        printf("\n==============================\n");
        printf(" INVENTORY MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Input Product Details\n");
        printf("2. Display All Products\n");
        printf("3. Inventory Summary\n");
        printf("4. Search Product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter number of products (max 10): ");
            scanf("%d", &n);
            if (n > 10) n = 10;

            for (i = 0; i < n; i++) {
                printf("\nEnter details for product %d:\n", i + 1);
                printf("Product ID: ");
                scanf("%d", &productID[i]);
                printf("Product Name: ");
                scanf(" %[^\n]", productName[i]); // allows spaces
                printf("Quantity in stock: ");
                scanf("%d", &quantity[i]);
                printf("Price per item: ");
                scanf("%f", &price[i]);
            }

            printf("\nProduct details entered successfully!\n");
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo products available. Please input details first.\n");
            } else {
                printf("\n%-10s %-20s %-10s %-10s %-10s\n",
                       "Prod ID", "Product Name", "Quantity", "Price", "Value");
                printf("-------------------------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-10d %-20s %-10d %-10.2f %-10.2f\n",
                           productID[i], productName[i], quantity[i],
                           price[i], quantity[i] * price[i]);
                }
            }
        }

        else if (choice == 3) {
            if (n == 0) {
                printf("\nNo products available. Please input details first.\n");
            } else {
                totalValue = 0;
                highestValue = quantity[0] * price[0];
                lowestValue = quantity[0] * price[0];
                highestIndex = 0;
                lowestIndex = 0;

                for (i = 0; i < n; i++) {
                    float currentValue = quantity[i] * price[i];
                    totalValue += currentValue;

                    if (currentValue > highestValue) {
                        highestValue = currentValue;
                        highestIndex = i;
                    }
                    if (currentValue < lowestValue) {
                        lowestValue = currentValue;
                        lowestIndex = i;
                    }
                }

                printf("\nTotal Inventory Value: %.2f\n", totalValue);
                printf("Highest Value Product: %s (%.2f)\n",
                       productName[highestIndex], highestValue);
                printf("Lowest Value Product: %s (%.2f)\n",
                       productName[lowestIndex], lowestValue);
            }
        }

        else if (choice == 4) {
            if (n == 0) {
                printf("\nNo products available. Please input details first.\n");
            } else {
                printf("\nEnter Product ID to search: ");
                scanf("%d", &searchID);
                found = 0;

                for (i = 0; i < n; i++) {
                    if (productID[i] == searchID) {
                        printf("\nProduct Found:\n");
                        printf("Product ID: %d\n", productID[i]);
                        printf("Name: %s\n", productName[i]);
                        printf("Quantity: %d\n", quantity[i]);
                        printf("Price: %.2f\n", price[i]);
                        printf("Value: %.2f\n", quantity[i] * price[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("\nProduct with ID %d not found.\n", searchID);
            }
        }

        else if (choice == 5) {
            printf("\nExiting program... Goodbye!\n");
            break;
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }
 
    return 0;
}
