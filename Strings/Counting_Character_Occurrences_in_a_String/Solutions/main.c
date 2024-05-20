/*Problem: Count the occurrences of a given character in a string.
WTD: Count how many times a specified character appears in a given string.
e.g.: I/P: "apple", Char: 'p', O/P: "2"*/

#include <stdio.h>

// Function to count occurrences of a character in a string
int countOccurrences(char str[], char ch) {
    int count = 0;

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++; // Increment count if the character matches
        }
    }

    return count; // Return the total count of occurrences
}

int main() {
    char str[100];
    char ch;
    
    // Input string from the user
    printf("Enter a string: ");
    scanf("%s", str);

    // Input character from the user
    printf("Enter a character: ");
    scanf(" %c", &ch); // Note the space before %c to consume any leading whitespace

    // Count occurrences of the specified character
    int occurrences = countOccurrences(str, ch);

    // Output the result
    printf("Occurrences of '%c' in \"%s\": %d\n", ch, str, occurrences);

    return 0;
}
