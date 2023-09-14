/*Implement binary search recursively.

*WTD: Create a function that uses recursion to implement binary search on a sorted array. Your function should make a recursive call after halving the array based on the comparison with the target element.

*Algorithm: Recursive binary search reduces the problem size by half in each recursive call.

*(e.g.: I/P: [1, 2, 3, 4, 5], 3 ; O/P: 2)

* author : Vaaarad07

*/

#include <stdio.h>

int binsearch(int arr[], int key, int min_index, int max_index){
    
    int mid = min_index + (max_index - min_index) / 2;       // equivalent to --> [(left+right)/2]
    if(min_index <= max_index){
        if(arr[mid] == key){
            printf("Key found.\n\n");
            return 1;
        }
        else if(arr[mid] > key){
            max_index = mid-1;
            binsearch(arr, key, min_index, max_index);      //recursive call
        }
        else if(arr[mid] < key){
            min_index = mid+1;
            binsearch(arr, key, min_index, max_index);      //recursive call
        }
    }
    else{
        printf("Key not found.\n\n");
        return 0;
    }
}

int main(){
    int arr[5] = {0,1,5,7,8};                           //specimen array
    int key = 8;                                        //no. to be found
    int max_index = sizeof(arr) / sizeof(arr[0]) - 1;   //max index of the array
    int a = binsearch(arr,key,0,max_index);             
}