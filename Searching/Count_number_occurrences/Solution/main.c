/*
countno occurrences of a number in a sorted array.

WTD: Develop a function that countnos the occurrences of a given element in a sorted array. Use a modified binary search to find the first and last occurrences, then calculate the countno.

Algorithm: Modified binary search to find the first and last occurrences.

(e.g.: I/P: [2, 2, 2, 2, 2], 2 ; O/P: 5)

author : Vaaarad07
*/

//  2,2,2,2,2

#include <stdio.h>

//get first occurance --> get last occurance --> last -first

 int getfirst(int arr[], int size, int element) {
    int left = 0;
    int right = size - 1;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            result = mid;
            right = mid - 1; // Continue searching in the left part
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

 int getlast(int arr[], int size, int element) {
    int left = 0;
    int right = size - 1;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            result = mid;
            left = mid + 1; // Continue searching in the right part
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

 int countno(int arr[], int size, int element) {
    int firstIndex = getfirst(arr, size, element);
     
    int lastIndex = getlast(arr, size, element);

     return (lastIndex - firstIndex + 1);
}

int main() {
    int arr[] = {0, 2, 2, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 2;

    int count = countno(arr, size, element);

    printf("The element occurs %d times in the array.\n",count);

    return 0;
}
