/*
 * Check if a number is a multiple of 3 using bit manipulation.
 *
 * @Author: Rohith B Narasimhamurthy (https://github.com/rohith-bn)
 *
 * Logic:
 * Binary place values have repeating remainders when divided by 3:
 *
 *   value:      16   8   4   2   1
 *   value % 3:   1   2   1   2   1
 *
 * Since 2 mod 3 behaves like -1 mod 3, those positions can be treated as:
 *
 *   value:      16   8   4   2   1
 *   sign:       +1  -1  +1  -1  +1
 *
 * So set bits in even positions from the right contribute +1, and set bits in
 * odd positions contribute -1. If the absolute difference between those counts
 * eventually reduces to 0, the original number is a multiple of 3.
 *
 * Examples:
 *   9  = 1001: 8 contributes -1 and 1 contributes +1, total 0.
 *   10 = 1010: 8 contributes -1 and 2 contributes -1, total -2.
 *   21 = 10101: 16, 4, and 1 contribute +1 each, total 3, which reduces to 0.
 */

#include <stdio.h>

int is_multiple_of_3(int num) {
    // Handle negative numbers by converting them to positive
    if (num < 0) {
        num = -num;
    }

    // Keep reducing the difference until the result is either 0 or 1.
    while (num > 1) {
        int even_count = 0;
        int odd_count = 0;

        // Count the number of set bits in even and odd positions.
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
    // If the final result is 0, then the original number is a multiple of 3.
    return num == 0;
}

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
