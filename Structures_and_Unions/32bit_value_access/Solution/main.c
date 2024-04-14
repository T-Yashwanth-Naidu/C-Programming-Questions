#include <stdio.h>
#include <stdint.h>

// Define a union named BitValue
union BitValue {
    uint32_t number;  // 32-bit unsigned integer

    // Structure to access the 32-bit value as two 16-bit values
    struct {
        uint16_t low;   // Lower 16 bits
        uint16_t high;  // Higher 16 bits
    };

    // Structure to access the 32-bit value as four 8-bit values
    struct {
        uint8_t b0;     // First 8 bits (LSB)
        uint8_t b1;     // Second 8 bits
        uint8_t b2;     // Third 8 bits
        uint8_t b3;     // Fourth 8 bits (MSB)
    };
};

int main() {
    // Declare a variable of type union BitValue
    union BitValue value;

    // Assign a 32-bit value (0xABCD1234) to the union's number member
    value.number = 0xABCD1234;

    // Print the 16-bit values (low and high parts)
    printf("16-bit: 0x%X, 0x%X\n", value.low, value.high);

    // Print the 8-bit values (bytes b0 to b3)
    printf("8-bit: 0x%X, 0x%X, 0x%X, 0x%X\n", value.b0, value.b1, value.b2, value.b3);

    return 0;
}
