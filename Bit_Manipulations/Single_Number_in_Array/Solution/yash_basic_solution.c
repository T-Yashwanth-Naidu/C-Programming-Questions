/*
Single Number in Array. Given an array where every element appears twice except
for one, find the element using bitwise operations.

WTD: You are given an array where each element appears exactly twice except for
one element, which appears only once. Find that unique element using bitwise
operations. Do this in constant space.

(e.g.: I/P:  [4,1,2,1,2]; O/P: 4)

Approach:
- Use given input, demo the output.
- XOR each element in the array.
- Very Basic Approach.

@Author: Yashwanth Naidu Tikkisetty (https://github.com/T-Yashwanth-Naidu)
*/

#include <stdio.h>

int main() {

  const int array[] = {4, 1, 2, 1, 2};
  int result_var = 0;

  for (int i = 0; i < 5; i++) {
    result_var ^= array[i];
  }

  printf("Value is: %d\n", result_var);

  return 0;
}
