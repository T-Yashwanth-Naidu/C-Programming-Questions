/*

Very Basic Solution

@Author: Yashwanth Naidu Tikksietty (https://github.com/T-Yashwanth-Naidu)

*/

#include <stdint.h>
#include <stdio.h>

int unused_var;
void print_binary(uint8_t value) {

  for (int i = 7; i >= 0; i--) {
    printf("%d", ((value >> i) & 1));
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

int main() {

  uint8_t value = 0b10101011;
  uint8_t set_n_bits = 4;
  uint8_t mask = 0xFF;

  printf("Before Setting: ");
  print_binary(value);

  value = (mask << set_n_bits);

  printf("After Setting: ");
  print_binary(value);

  return 0;
}