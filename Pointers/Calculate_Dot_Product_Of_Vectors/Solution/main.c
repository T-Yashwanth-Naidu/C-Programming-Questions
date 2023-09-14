/*Write a function to calculate the dot product of two vectors using pointers.

WTD: Traverse both vectors, multiplying corresponding elements and summing the results.

(e.g.: I/P: int vec1[] = {1,2,3}, vec2[] = {4,5,6} ,O/P: 32 )
*/

#include <stdio.h>
     
int getDot(int arr3[], int arr4[], int size){
    int sum = 0;
     for(int i = 0; i < size; i++){
        sum += (arr3[i] * arr4[i]);
     }
     return sum;
}

int main(){
    int arr1[] = {1,2,4};
    int arr2[] = {4,5,6};
    int size = 3;   //size of array having less elements
    printf("\nAnswer is: %d\n\n",getDot(arr1,arr2, 3));
}