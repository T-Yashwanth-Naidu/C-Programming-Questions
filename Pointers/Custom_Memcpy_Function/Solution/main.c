/*Design a function similar to memcpy() that copies memory areas using pointers.

WTD: Use pointers to traverse both the source and destination and copy each byte.

(e.g.: I/P: Source = "hello", Destination (empty buffer), Length = 5 ; O/P: Destination = "hello")*/

#include <stdio.h>

// Function to copy 'n' characters from source to destination
void mem_cpy(char *dst, char *src, int n) {
    // Iterate through the source string until the null terminator is reached
    while (*src != '\0') {
        // Copy the character from source to destination
        *dst = *src;
        
        // Move to the next character in both source and destination strings
        dst++;
        src++;
        
        // Decrement 'n' to keep track of the number of characters remaining to copy
        n--;
        
        // Check if all 'n' characters have been copied
        if (n == 0)
            break;
    }
    // Add a null terminator to the end of the destination string
    *dst = '\0';
}

int main() {
    // Declare source and destination character arrays
    char src[] = "Hello";
    int n = sizeof(src) / sizeof(src[0]); // Calculate the size of the source array
    char dst[n]; // Declare destination array with the same size as source array
    
    // Print the content of the destination array before copying
    printf("Before using mem_cpy at destination: %s\n", dst);
    
    // Call the mem_cpy function to copy 'n' characters from source to destination
    mem_cpy(dst, src, n);
    
    // Print the content of the destination array after copying
    printf("After using mem_cpy at destination: %s", dst);

    return 0;
}
