/*Write a function that converts a string to lowercase using pointers.

WTD: Traverse the string. For each character, if it's uppercase, add 32 to convert it to lowercase.

(e.g.: I/P: "HELLO" ,O/P: "hello" )*/

#include <stdio.h>

// Function to change the case of characters in a string to lowercase
void ChangeCase(char *str) {
    // Iterate through each character in the string until the null terminator is reached
    while (*str != '\0') {
        // Check if the current character is uppercase
        if (*str >= 'A' && *str <= 'Z') {
            // If the character is uppercase, convert it to lowercase by adding 32 to its ASCII value
            *str += 32;
        }
        // Move to the next character in the string
        str++;
    }
}

int main() {
    // Declare a character array containing an uppercase string
    char str[] = "HELLO";

    // Call the ChangeCase function to change the case of characters in the string to lowercase
    ChangeCase(str);

    // Print the modified string
    printf("%s", str);

    return 0;
}
