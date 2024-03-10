/*Design a program that checks if a string is a prefix of another string using pointers.

WTD: Traverse both strings using two pointers. If all characters of the shorter string match the beginning of the longer string, return True.

(e.g.: I/P: char *str1 = "Hello", *str2 = "Hel" ,O/P: True )*/

#include <stdio.h>

// Function to check if str2 is a prefix of str1
int prefix_check(char *str1, char *str2) {
    // Iterate through characters of str2 until '\0' (end of string) is encountered
    while (*str2 != '\0') {
        // If characters at current positions of str1 and str2 don't match, return 0 (False)
        if (*str2 != *str1) {
            return 0;
        }
        // Move to the next character in both strings
        str1++;
        str2++;
    }
    // If the loop completes without returning, str2 is a prefix of str1, so return 1 (True)
    return 1;
}

int main() {
    // Define two strings
    char str1[] = "hello";
    char str2[] = "hel";

    // Call the prefix_check function and check the result
    if (prefix_check(str1, str2)) {
        printf("True"); // If str2 is a prefix of str1, print "True"
    } else {
        printf("False"); // If str2 is not a prefix of str1, print "False"
    }

    return 0;
}
