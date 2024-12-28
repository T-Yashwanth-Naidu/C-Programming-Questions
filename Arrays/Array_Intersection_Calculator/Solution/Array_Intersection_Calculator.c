/*
 * Determine the intersection of two integer arrays.
 *
 * Description:
 * Compare every element of the two arrays and find common integers that appear in both.
 *
 * Example:
 * Input: [1, 2, 4, 5, 6], [2, 3, 5, 7]
 * Output: [2, 5]
 * Author: Yashwanth Naidu Tikkisetty
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY1_SIZE 4
#define ARRAY2_SIZE 6

/*
 * Function: calculateIntersection
 * Description:
 * This function finds the common elements between two arrays and stores them in a dynamically allocated result array.
 * 
 * Parameters:
 * - array1: Pointer to the first integer array.
 * - array2: Pointer to the second integer array.
 * - resultArray: Pointer to the pointer where the result array will be stored.
 * - array1_size: Size of the first array.
 * - array2_size: Size of the second array.
 * - commoncount: Pointer to an integer that will store the number of common elements.
 */
void calculateIntersection(int *array1, int *array2, int **resultArray, int array1_size, int array2_size, int *commoncount) {
    *commoncount = 0;

    // Allocate temporary buffer for common elements
    int *buffer = (int *)malloc((array1_size < array2_size ? array1_size : array2_size) * sizeof(int));

    // Find common elements
    for (int i = 0; i < array1_size; i++) {
        for (int j = 0; j < array2_size; j++) {
            if (array1[i] == array2[j]) {
                // Avoid duplicates in the buffer
                int isDuplicate = 0;
                for (int k = 0; k < *commoncount; k++) {
                    if (buffer[k] == array1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    buffer[*commoncount] = array1[i];
                    (*commoncount)++;
                }
            }
        }
    }

    // Allocate memory for the result array
    *resultArray = (int *)malloc(*commoncount * sizeof(int));
    for (int i = 0; i < *commoncount; i++) {
        (*resultArray)[i] = buffer[i];
    }

    // Free the temporary buffer
    free(buffer);
}

int main(void) {
    srand(time(NULL));

    // Dynamically allocate memory for the two arrays
    int *array1 = (int *)malloc(ARRAY1_SIZE * sizeof(int));
    int *array2 = (int *)malloc(ARRAY2_SIZE * sizeof(int));
    int *resultArray = NULL; // Pointer to hold the result array
    int commoncount = 0;     // Variable to store the number of common elements

    // Populate the arrays with random integers
    for (int i = 0; i < ARRAY1_SIZE; i++) {
        array1[i] = rand() % 10;
    }

    for (int i = 0; i < ARRAY2_SIZE; i++) {
        array2[i] = rand() % 10;
    }

    // Print the two arrays
    printf("Array1: ");
    for (int i = 0; i < ARRAY1_SIZE; i++) {
        printf("%d ", array1[i]);
    }

    printf("\nArray2: ");
    for (int i = 0; i < ARRAY2_SIZE; i++) {
        printf("%d ", array2[i]);
    }

    // Calculate the intersection of the two arrays
    calculateIntersection(array1, array2, &resultArray, ARRAY1_SIZE, ARRAY2_SIZE, &commoncount);

    // Print the number of common elements and the result
    printf("\nNumber of common elements: %d", commoncount);
    printf("\nCommon Elements: ");
    for (int i = 0; i < commoncount; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");

    // Free allocated memory
    free(array1);
    free(array2);
    free(resultArray);

    return 0;
}
