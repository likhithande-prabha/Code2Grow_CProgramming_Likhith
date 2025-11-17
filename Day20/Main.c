#include <stdio.h>

#define MAX_PRODUCTS 20
#define RACK_SIZE 3

void addProduct(int ids[], int qty[], int price[], int *count);
void searchProduct(int ids[], int qty[], int price[], int count);
void updateQuantity(int ids[], int qty[], int count);
void rackReport();
void calculateStockValue(int ids[], int qty[], int price[], int count);
void displayAll(int ids[], int qty[], int price[], int count);

int findProduct(int ids[], int count, int id);

int main() {
    int ids[MAX_PRODUCTS], qty[MAX_PRODUCTS], price[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== SMART WAREHOUSE ANALYTICS SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Search Product (By ID)\n");
        printf("3. Update Quantity\n");
        printf("4. Generate Rack Report (3x3 Matrix)\n");
        printf("5. Calculate Stock Value\n");
        printf("6. Display All Products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addProduct(ids, qty, price, &count); break;
            case 2: searchProduct(ids, qty, price, count); break;
            case 3: updateQuantity(ids, qty, count); break;
            case 4: rackReport(); break;
            case 5: calculateStockValue(ids, qty, price, count); break;
            case 6: displayAll(ids, qty, price, count); break;
            case 0: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}


void addProduct(int ids[], int qty[], int price[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Warehouse full! Cannot add more products.\n");
        return;
    }

    int id, q, p;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    if (findProduct(ids, *count, id) != -1) {
        printf("Duplicate ID! Product already exists.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &q);
    printf("Enter Price per unit: ");
    scanf("%d", &p);

    if (q <= 0 || p <= 0) {
        printf("Quantity and Price must be positive!\n");
        return;
    }

    ids[*count] = id;
    qty[*count] = q;
    price[*count] = p;
    (*count)++;

    printf("Product added successfully!\n");
}

void searchProduct(int ids[], int qty[], int price[], int count) {
    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    int index = findProduct(ids, count, id);
    if (index == -1) {
        printf("Product Not Found.\n");
    } else {
        printf("Product Found!\n");
        printf("ID: %d | Quantity: %d | Price: %d\n", ids[index], qty[index], price[index]);
    }
}


void updateQuantity(int ids[], int qty[], int count) {
    int id, choice, value;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    int index = findProduct(ids, count, id);
    if (index == -1) {
        printf("Product Not Found.\n");
        return;
    }

    printf("1. Increase Quantity\n2. Decrease Quantity\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter amount: ");
    scanf("%d", &value);

    if (value <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (choice == 1) {
        qty[index] += value;
        printf("Quantity increased. New Quantity: %d\n", qty[index]);
    } else if (choice == 2) {
        if (qty[index] - value < 0) {
            printf("Error: Quantity cannot be negative!\n");
        } else {
            qty[index] -= value;
            printf("Quantity decreased. New Quantity: %d\n", qty[index]);
        }
    } else {
        printf("Invalid option.\n");
    }
}


void rackReport() {
    int rack[RACK_SIZE][RACK_SIZE];
    int i, j;
    printf("Enter 3x3 Rack Matrix (numeric values only):\n");
    for (i = 0; i < RACK_SIZE; i++) {
        for (j = 0; j < RACK_SIZE; j++) {
            scanf("%d", &rack[i][j]);
        }
    }

    int max = rack[0][0], min = rack[0][0];
    int maxR = 0, maxC = 0, minR = 0, minC = 0;
    int total = 0;

    for (i = 0; i < RACK_SIZE; i++) {
        for (j = 0; j < RACK_SIZE; j++) {
            total += rack[i][j];
            if (rack[i][j] > max) {
                max = rack[i][j];
                maxR = i; maxC = j;
            }
            if (rack[i][j] < min) {
                min = rack[i][j];
                minR = i; minC = j;
            }
        }
    }

    printf("\n--- Rack Report ---\n");
    printf("Maximum stock: %d at position (%d,%d)\n", max, maxR, maxC);
    printf("Minimum stock: %d at position (%d,%d)\n", min, minR, minC);
    printf("Total items across racks: %d\n", total);
}


void calculateStockValue(int ids[], int qty[], int price[], int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    int i;
    int maxVal = qty[0] * price[0];
    int minVal = maxVal;
    int totalVal = 0;
    int maxID = ids[0], minID = ids[0];

    printf("\nID\tQuantity\tPrice\tStockValue\n");
    for (i = 0; i < count; i++) {
        int val = qty[i] * price[i];
        printf("%d\t%d\t\t%d\t%d\n", ids[i], qty[i], price[i], val);
        totalVal += val;
        if (val > maxVal) {
            maxVal = val;
            maxID = ids[i];
        }
        if (val < minVal) {
            minVal = val;
            minID = ids[i];
        }
    }

    printf("\nProduct with Highest Stock Value: ID %d (Value = %d)\n", maxID, maxVal);
    printf("Product with Lowest Stock Value: ID %d (Value = %d)\n", minID, minVal);
    printf("Total Warehouse Value: %d\n", totalVal);
}


void displayAll(int ids[], int qty[], int price[], int count) {
    if (count == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("\nID\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\n", ids[i], qty[i], price[i]);
    }
}

int findProduct(int ids[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (ids[i] == id)
            return i;
    }
    return -1;
}
