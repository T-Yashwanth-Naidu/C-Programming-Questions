/*
Rotate Bits. Design a program to rotate bits of a number to the left by  k
positions.

WTD: You have an integer and a number k. Rotate the bits of the integer to the
left by k positions using bitwise operations.

(e.g.: I/P:  0b10110011, k=3; O/P: 0b10011101)

*/

#include <stdint.h>
#include <stdio.h>

void print_binary(uint8_t number) {

  for (int i = 7; i >= 0; i--) {

    printf("%d", (number >> i) & 1);
    if (i != 0 && i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

void rotate_left(uint8_t *variable, uint8_t shift_by) {

  if (shift_by == 0)
    return;
  *variable = ((*variable) << shift_by) | ((*variable) >> (8 - shift_by));
}

int main() {

  uint8_t variable = 0b10110011;
  uint8_t shift_by = 3;

  printf("Initial Sate: ");
  print_binary(variable);

  rotate_left(&variable, shift_by);

  printf("Final State after Rotation: ");
  print_binary(variable);

  return 0;
}
