/*Write a function to calculate the dot product of two vectors using pointers.

WTD: Traverse both vectors, multiplying corresponding elements and summing the results.

(e.g.: I/P: int vec1[] = {1,2,3}, vec2[] = {4,5,6} ,O/P: 32 )*/

#include <stdio.h>

int Calculate_dot_prod(int vec1[], int vec2[], int len1, int len2){
    
    // Initialize variables to store the sum and product
    int sum = 0, prod = 1;
    
    // Loop through elements of the first array
    for (int i = 0; i < len1; i++) {
        // Loop through elements of the second array
        for (int j = 0; j < len2; j++) {
            // Multiply corresponding elements of both arrays and update the product
            prod = *(vec1 + i) * *(vec2 + i);
        }
        // Add the product to the sum
        sum += prod;
    }
    
    return sum;
}

int main()
{
    // Define two integer arrays
    int vec1[] = {1, 2, 3}, vec2[] = {4, 5, 6};
    
    // Calculate the length of each array
    int len1 = sizeof(vec1) / sizeof(vec1[0]);
    int len2 = sizeof(vec2) / sizeof(vec2[0]);
    
    // Print the sum
    printf("Sum is: %d", Calculate_dot_prod(vec1, vec2, len1, len2));

    return 0;
}