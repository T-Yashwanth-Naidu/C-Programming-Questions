#include <stdio.h>

void findIntersection(int arr1[], int arr2[], int len1, int len2) {
    printf("Intersection of the two arrays: [ ");
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break; // Break once we find a match to avoid duplicates
            }
        }
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, arr2, len1, len2);

    return 0;
}
