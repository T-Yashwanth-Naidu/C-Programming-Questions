#include <stdio.h>
#include <stdlib.h>

void intersectionOfTwoArrays(int* arr1, int len1, int* arr2, int len2) {
    int* arr3;
    int len3 = 0;

    // Allocate memory for arr3 based on the maximum possible size
    arr3 = (int*)malloc(len1 * sizeof(int));

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[len3++] = arr1[i];
                break; // Avoid adding duplicates
            }
        }
    }

    // Print the intersection
    for (int i = 0; i < len3; i++) {
        printf("%d ", arr3[i]);
    }

    // Free the allocated memory
    free(arr3);
}

int main() {
    int ar1[] = {1, 3, 5, 7};
    int ar2[] = {2, 3, 5, 8};
    int len1 = sizeof(ar1) / sizeof(ar1[0]);
    int len2 = sizeof(ar2) / sizeof(ar2[0]);

    intersectionOfTwoArrays(ar1, len1, ar2, len2);

    return 0;
}