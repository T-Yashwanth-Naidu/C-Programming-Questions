

// Check if a number is a multiple of 3 using bit manipulation

// @Author: Rohith B Narasimhamurthy (https://github.com/rohith-bn)

#include <stdio.h>
// Function to check if a number is a multiple of 3

int is_multiple_of_3(int num) {
    // Handle negative numbers by converting them to positive
    if (num < 0) {
        num = -num;
    }

    //if the result of first iteration, and diffrence of even and odd is not 0 , then we need this while loop.
    while (num > 1) {
        int even_count = 0;
        int odd_count = 0;

    // Count the number of set bits in even and odd positions
        while (num > 0) {
            if (num & 1) {
                even_count++;
            }
            num >>= 1;

            if (num & 1) {
                odd_count++;
            }
            num >>= 1;
        }

        num = even_count - odd_count;

        // Handle negative results by converting them to positive
        if (num < 0) {
            num = -num;
        }
    }
// If the final result is 0, then the original number is a multiple of 3
    return num == 0;
}

// after finding the difference between the count of even and odd bits,
//  we can check if the result is divisible by 3 or not.
// we can use modulo operator to check if the result

// we dont want to use modulo operator we can use recursion.

// this method avoids recursion and uses a loop to check.
// which is more efficient than the recursive approach

// logic behid this is explained in the readme file of this problem.

int main(void) {
    int num;

    // Prompt the user to enter a number
    printf("Enter the number: ");
    scanf("%d", &num); // Read the input number

    // Call the function is_multiple_of_3 to check if the number is a multiple of 3
    if (is_multiple_of_3(num)) {
        printf("%d is a multiple of 3.\n", num);
    } else {
        printf("%d is not a multiple of 3.\n", num);
    }

    return 0;
}