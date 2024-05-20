/*Problem: String Encoding.
WTD: : Encode a string by replacing each character with the third character after it in the alphabet. 
Wrap around to the start of the alphabet after 'z'.
e.g.: I/P: "abc", O/P: "def"*/

#include <stdio.h>
#include <string.h>

int main(){
    char data[10]; // Declare an array to store the input string (maximum length 9 + '\0' terminator)
    int offset = 3; // Define the offset for wrapping around the alphabet

    // Prompt the user to enter a string
    printf("Enter the string-\n");
    scanf("%s", data); // Read the input string from the user

    // Iterate through each character in the input string
    for(int i = 0; i < strlen(data); i++){
        // Check if the character is a lowercase letter ('a' to 'z')
        if(data[i] >= 'a' && data[i] <= 'z')
            // Apply wrapping by adding the offset and using modular arithmetic with 26
            data[i] = 'a' + (data[i] - 'a' + offset) % 26; 
    }

    // Print the encoded string
    printf("Encoded string is : ");
    for(int i = 0; i < strlen(data); i++)
        printf("%c", data[i]); // Print each character of the encoded string

    return 0;
}
