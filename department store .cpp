#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for product and customer
struct Product {
    int productId;
    char productName[50];
    float price;
    int quantity;
};

struct Customer {
    int customerId;
    char customerName[50];
};

// Function prototypes
void displayMenu();
void addProduct(struct Product products[], int *productCount);
void displayProducts(struct Product products[], int productCount);
void addCustomer(struct Customer customers[], int *customerCount);
void displayCustomers(struct Customer customers[], int customerCount);
void makeSale(struct Product products[], int productCount, struct Customer customers[], int customerCount);

int main() {
    struct Product products[100]; // Assuming a maximum of 100 products
    struct Customer customers[50]; // Assuming a maximum of 50 customers
    int productCount = 0;
    int customerCount = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                displayProducts(products, productCount);
                break;
            case 3:
                addCustomer(customers, &customerCount);
                break;
            case 4:
                displayCustomers(customers, customerCount);
                break;
            case 5:
                makeSale(products, productCount, customers, customerCount);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n=== !! Department Store Management System!! ===\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Add Customer\n");
    printf("4. Display Customers\n");
    printf("5. Make Sale\n");
    printf("0. Exit\n");
}

void addProduct(struct Product products[], int *productCount) {
    // Get product details from the user
    printf("Enter product name: ");
    getchar(); // Clear newline character from the buffer
    fgets(products[*productCount].productName, sizeof(products[*productCount].productName), stdin);

    printf("Enter product price: ");
    scanf("%f", &products[*productCount].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[*productCount].quantity);

    // Assign a unique product ID (you can generate this in a more sophisticated way)
    products[*productCount].productId = *productCount + 1;

    // Increment the product count
    (*productCount)++;

    printf("Product added successfully!\n");
}

void displayProducts(struct Product products[], int productCount) {
    // Display the list of products
    printf("Displaying products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("(%d) %s - $%.2f - Quantity: %d\n", products[i].productId, products[i].productName,
               products[i].price, products[i].quantity);
    }
}

void addCustomer(struct Customer customers[], int *customerCount) {
    // Check if the maximum number of customers has been reached
    if (*customerCount >= 50) {
        printf("Maximum number of customers reached. Cannot add more.\n");
        return;
    }

    // Get customer details from the user
    printf("Enter customer name: ");
    getchar(); // Clear newline character from the buffer
    fgets(customers[*customerCount].customerName, sizeof(customers[*customerCount].customerName), stdin);

    // Assign a unique customer ID (you can generate this in a more sophisticated way)
    customers[*customerCount].customerId = *customerCount + 1;

    // Increment the customer count
    (*customerCount)++;

    printf("Customer added successfully!\n");
}

void displayCustomers(struct Customer customers[], int customerCount) {
    // Display the list of customers
    printf("Displaying customers:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("(%d) %s\n", customers[i].customerId, customers[i].customerName);
    }
}

void makeSale(struct Product products[], int productCount, struct Customer customers[], int customerCount) {
    // Placeholder code to make a sale
    printf("Making a sale:\n");

    // Display available products
    displayProducts(products, productCount);

    // Get product ID and quantity from the user
    int productId, quantity;
    printf("Enter the product ID to sell: ");
    scanf("%d", &productId);

    // Find the product
    int productIndex = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].productId == productId) {
            productIndex = i;
            break;
        }
    }

    // Check if the product was found
    if (productIndex == -1) {
        printf("Product not found. Sale aborted.\n");
        return;
    }

    printf("Enter the quantity to sell: ");
    scanf("%d", &quantity);

    // Check if there is enough stock
    if (quantity > products[productIndex].quantity) {
        printf("Not enough stock. Sale aborted.\n");
        return;
    }

    // Calculate the total price
    float totalPrice = quantity * products[productIndex].price;

    // Update product quantity
    products[productIndex].quantity -= quantity;

    printf("Sale successful!\n");
    printf("Total Price: $%.2f\n", totalPrice);
}


