#include <stdio.h>

// Function to count the number of set bits (1s) in an integer
int count_set_bits(int num) {
    int count = 0; // Initialize the count of set bits
    
    // Iterate until num becomes 0
    while (num) {
        // Using num & (num - 1) clears the rightmost set bit (1) in num
        // This operation is used to count the number of set bits in num
        num = num & (num - 1);
        count++; // Increment the count for each cleared bit
    }
    
    return count; // Return the total count of set bits
}

int main() {
    int num;
    
    // Prompt the user to enter a number
    printf("Enter the number: ");
    scanf("%d", &num); // Read the input number
    
    // Call the function count_set_bits to count the set bits in the input number
    int set_bits_count = count_set_bits(num);
    
    // Display the count of set bits in the input number
    printf("Number of set bits in %d: %d\n", num, set_bits_count);
    
    return 0; // Return 0 to indicate successful execution
}
