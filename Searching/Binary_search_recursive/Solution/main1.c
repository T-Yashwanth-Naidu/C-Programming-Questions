/*Implement binary search recursively.

*WTD: Create a function that uses recursion to implement binary search on a sorted array. Your function should make a recursive call after halving the array based on the comparison with the target element.

*Algorithm: Recursive binary search reduces the problem size by half in each recursive call.

*(e.g.: I/P: [1, 2, 3, 4, 5], 3 ; O/P: 2)

* author : Sahana K

*/

#include<stdio.h>
#include<stdlib.h>

// Function for binary search
int binarySearch(int arr[], int x, int low, int high) {
    int mid = (low + high) / 2;

    // If the element is found at mid, return its index
    if (x == arr[mid])
        return mid;
    else {
        // If x is greater than the middle element, search in the right half
        if (x > arr[mid])
            return binarySearch(arr, x, mid + 1, high);
        // If x is smaller than the middle element, search in the left half
        else
            return binarySearch(arr, x, low, mid - 1);
    }
}

int main() {
    int size;
    int *arr;

    // Get the size of the array from the user
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    arr = (int*)malloc(size * sizeof(int));

    // Read elements into the array from the user
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int x;

    // Get the element to be searched from the user
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Perform binary search and get the position of the element
    int position = binarySearch(arr, x, 0, size - 1);

    // Print the position of the element
    printf("Position of element: %d\n", position);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
