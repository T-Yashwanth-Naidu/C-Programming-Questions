/* Create a structure for a book with title, author, and price. Implement a function to discount the book's price by a given percentage.

WTD: Design a function that applies a specified discount percentage to the book's price, updating its value accordingly.

(e.g: I/P: Title: "Pride and Prejudice", Author: "Austen", Price: $30, Discount: 15%; O/P: New Price: $25.5 )
*/

#include <stdio.h>

// Define a structure for a book
struct Book {
    char title[50]; // Title of the book
    char author[50]; // Author of the book
    float price; // Price of the book
    float discount; // Discount percentage
};

// Function to calculate and apply discount to the book's price
void Discount_Calculator(struct Book *b1) {
    // Calculate the discount amount
    float discountAmount = (b1->discount / 100) * b1->price;
    
    // Apply the discount to the book's price
    b1->price -= discountAmount;
}

int main() {
    // Create an instance of struct Book and initialize it
    struct Book b1 = {"Pride and Prejudice", "Austen", 30.0, 15.0};
    
    // Call the Discount_Calculator function to apply the discount
    Discount_Calculator(&b1);
    
    printf("Discounted Price: $%.2f\n", b1.price); // Display the discounted price

    return 0;
}