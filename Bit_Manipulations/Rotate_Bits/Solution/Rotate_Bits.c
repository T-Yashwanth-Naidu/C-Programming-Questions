// Logic: rotate-left = shift-left OR shift-right-by-complement.
//
//   (value << normalized_shift)
//       -> bits move toward MSB; top bits fall off.
//   (value >> (width - normalized_shift))
//       -> recovers the bits that fell off and brings them to the LSB side.
//
//   OR combines both halves into the rotated result.
//   & 0xFFFF strips bits introduced by integer promotion to int,
//   keeping only the lower 16 bits relevant to uint16_t.
//
//   normalized_shift is in [1, width-1] (0 was handled earlier),
//   so neither shift amount is 0 or >= width, avoiding undefined behavior.

// clang-format off
/*
 * Current Program Output:
 *
 * (8-Bit UINT)
 * Initial State:              10110011
 * Final State after Rotation: 10011101
 *
 * (16-Bit UINT)
 * Initial State:              11110000 00000000
 * Final State after Rotation: 10000000 00000111
 *
 * (32-Bit UINT)
 * Initial State:              11110000 00000000 00000000 00000000
 * Final State after Rotation: 10000000 00000000 00000000 00000111
 *
 * (64-Bit UINT)
 * Initial State:              11111111 00000000 00000000 00000000 00000000 00000000 00000000 00000000
 * Final State after Rotation: 11111000 00000000 00000000 00000000 00000000 00000000 00000000 00000111
 */
// clang-format on
// @ Author: Yashwanth Naidu Tikkisetty (https://github.com/T-Yashwanth-Naidu)

#include <stdint.h>
#include <stdio.h>

uint8_t rotate_left_u8(uint8_t value, uint8_t shift);
uint16_t rotate_left_u16(uint16_t value, uint8_t shift);
uint32_t rotate_left_u32(uint32_t value, uint8_t shift);
uint64_t rotate_left_u64(uint64_t value, uint8_t shift);
void print_binary(uint64_t number, uint8_t width);

// Generic macro to select the appropriate function based on the type of 'value'
#define rotate_left(value, shift)                                              \
  _Generic((value),                                                            \
      uint8_t: rotate_left_u8,                                                 \
      uint16_t: rotate_left_u16,                                               \
      uint32_t: rotate_left_u32,                                               \
      uint64_t: rotate_left_u64)((value), (shift))

void print_binary(uint64_t number, uint8_t width) {

  // Print the binary representation of the number with spaces every 8 bits
  for (int i = width - 1; i >= 0; i--) {

    // Print the bit at position i. Typecast to int for proper formatting
    printf("%d", (int)(number >> i) & 1);
    // Add a space after every 8 bits for better readability
    if ((i != 0) && (i % 8 == 0)) {
      printf(" ");
    }
  }
  printf("\n");
}

// Function to rotate bits to the left for 8-bit unsigned integer
uint8_t rotate_left_u8(uint8_t value, uint8_t shift) {

  const uint8_t width = 8;

  uint8_t normalized_shift =
      shift % width; // Ensures the width is within the range [0,width-1]
  if (normalized_shift == 0) {
    return value; // No change
  }

  // Perform the left rotation
  uint8_t result =
      ((value << normalized_shift) | (value >> (width - normalized_shift))) &
      0xFF;

  return result;
}

uint16_t rotate_left_u16(uint16_t value, uint8_t shift) {

  const uint8_t width = 16;

  uint8_t normalized_shift =
      shift % width; // Ensures the width is within the range [0,width-1]
  if (normalized_shift == 0) {
    return value; // No change
  }

  // Perform the left rotation
  uint16_t result =
      ((value << normalized_shift) | (value >> (width - normalized_shift))) &
      0xFFFF;

  return result;
}

uint32_t rotate_left_u32(uint32_t value, uint8_t shift) {

  const uint8_t width = 32;

  uint8_t normalized_shift =
      shift % width; // Ensures the width is within the range [0,width-1]
  if (normalized_shift == 0) {
    return value; // No change
  }

  // Perform the left rotation
  uint32_t result =
      (value << normalized_shift) | (value >> (width - normalized_shift));

  return result;
}

uint64_t rotate_left_u64(uint64_t value, uint8_t shift) {

  const uint8_t width = 64;

  uint8_t normalized_shift =
      shift % width; // Ensures the width is within the range [0,width-1]
  if (normalized_shift == 0) {
    return value; // No change
  }

  // Perform the left rotation
  uint64_t result =
      (value << normalized_shift) | (value >> (width - normalized_shift));

  return result;
}

int main() {

  uint8_t variable_8 = 0b10110011;              // 0xB3
  uint16_t variable_16 = 0b1111000000000000;    // 0xF000
  uint32_t variable_32 = 0xF0000000;            // four 1s at the top
  uint64_t variable_64 = 0xFF00000000000000ULL; // one byte at the top
  uint8_t shift_by = 3;

  // Function call for 8-bit
  printf("\n(8-Bit UINT)\n");
  printf("Initial State: ");
  print_binary(variable_8, sizeof(variable_8) * 8);

  variable_8 = rotate_left(variable_8, shift_by);

  printf("Final State after Rotation: ");
  print_binary(variable_8, sizeof(variable_8) * 8);

  // Function call for 16-bit
  printf("\n(16-Bit UINT)\n");
  printf("Initial State: ");
  print_binary(variable_16, sizeof(variable_16) * 8);

  variable_16 = rotate_left(variable_16, shift_by);

  printf("Final State after Rotation: ");
  print_binary(variable_16, sizeof(variable_16) * 8);

  // Function call for 32-bit
  printf("\n(32-Bit UINT)\n");
  printf("Initial State: ");
  print_binary(variable_32, sizeof(variable_32) * 8);

  variable_32 = rotate_left(variable_32, shift_by);

  printf("Final State after Rotation: ");
  print_binary(variable_32, sizeof(variable_32) * 8);

  // Function call for 64-bit
  printf("\n(64-Bit UINT)\n");
  printf("Initial State: ");
  print_binary(variable_64, sizeof(variable_64) * 8);

  variable_64 = rotate_left(variable_64, shift_by);

  printf("Final State after Rotation: ");
  print_binary(variable_64, sizeof(variable_64) * 8);

  return 0;
}
