/* Compute the product of an array except self. 

WTD: For every index in the array, calculate the product of all numbers except for the number at that index.

(e.g.: I/P: [1,2,3,4], O/P: [24,12,8,6])*/

#include <stdio.h> 
#include <stdlib.h> 

void productArray(int arr[], int n) 
{ 
	// Base case 
	if (n == 1) { 
		printf("0"); 
		return; 
	} 

	//Step 1: Dynamically allocating memories
	int* left = (int*)malloc(sizeof(int) * n); 
	int* right = (int*)malloc(sizeof(int) * n); 
	int* prod = (int*)malloc(sizeof(int) * n); 

	int i, j; 

	left[0] = 1; 
	right[n - 1] = 1; 

	//step 2: Construct the left array
	for (i = 1; i < n; i++) 
		left[i] = arr[i - 1] * left[i - 1]; 

	//Step 3: Construct the right array
	for (j = n - 2; j >= 0; j--) 
		right[j] = arr[j + 1] * right[j + 1]; 

	//Step 4: Construct the product array using left[] and right[]
	for (i = 0; i < n; i++) 
		prod[i] = left[i] * right[i]; 

	/* print the constructed prod array */
	for (i = 0; i < n; i++) 
		printf("%d ", prod[i]); 

	return; 
} 

int main() 
{ 
    //input array
	int arr[] = { 1,2,3,4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	productArray(arr, n); 
}

