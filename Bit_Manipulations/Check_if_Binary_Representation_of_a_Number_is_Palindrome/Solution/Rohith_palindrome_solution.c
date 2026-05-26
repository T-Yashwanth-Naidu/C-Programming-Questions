// @Author: Rohith B Narasimhamurthy (https://github.com/rohith-bn)

#include <stdio.h>

// Function to check if the binary representation of a number is a palindrome
int check_palindrome(int num) {
    int reversed = 0; // Initialize the variable to store the reversed binary number
    int original = num; // Store the original number for comparison

    // Reverse the binary representation of the number
    while (num > 0) {
        reversed <<= 1; // Shift the reversed number left by 1 bit
        reversed |= (num & 1); // Add the least significant bit of num to reversed
        num >>= 1; // Shift num right by 1 bit to process the next bit
    }

    // Check if the original number is equal to its reversed version
    return original == reversed; // Return 1 (true) if it's a palindrome, otherwise return 0 (false)
}

// helper funtion to visualize the binary representation of a number (not required for the main functionality)

void print_binary(unsigned int num) {

    if (num == 0) {
        printf("0");
        return;
    }

    int started = 0; // Flag to indicate when to start printing bits

    for (int i = 31; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1u; // Extract the i-th bit of num
        // num & (1u << i) can also be used to extract the i-th bit, but the above method is more concise and efficient
        if (bit) {
            started = 1; // Set the flag to start printing when we encounter the first 1
        }
        if (started) {
            printf("%u", bit); // Print the bit if we've started printing
        }
    }
}


int main(void) {
    int num;

    // Prompt the user to enter a number
    printf("Enter the number: ");

    scanf("%d", &num); // Read the input number

    printf("Binary representation of %d: ", num);
    print_binary((unsigned int)num); // Print the binary representation of the input number
    printf("\n");

    // Call the function check_palindrome to check if the binary representation is a palindrome
    if (check_palindrome(num)) {
        printf("The binary representation of %d is a palindrome.\n", num);
    } else {
        printf("The binary representation of %d is not a palindrome.\n", num);
    }

    return 0; // Return 0 to indicate successful execution
}
