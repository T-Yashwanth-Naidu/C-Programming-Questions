#include <stdio.h>
#include <string.h>
#include <math.h>

// Define a structure for complex numbers
typedef struct Complex {
    float real; // Real part
    float img;  // Imaginary part
} complex;

// Function prototypes for arithmetic operations
complex add(complex n1, complex n2);
complex sub(complex n1, complex n2);
complex mul(complex n1, complex n2);
complex division(complex n1, complex n2);

int main() {
    complex n1, n2, result;
    char option[20];

    // Input the first complex number
    printf("1st number (comma separated real, imaginary parts): \n");
    scanf("%f, %f", &n1.real, &n1.img);

    // Input the second complex number
    printf("2nd number (comma separated real, imaginary parts): \n");
    scanf("%f, %f", &n2.real, &n2.img);

    // Input the arithmetic operation option
    printf("Enter an option (add, subtract, multiply, divide): ");
    scanf("%s", option);

    // Perform the selected arithmetic operation
    if (strcmp(option, "add") == 0) {
        result = add(n1, n2);
    } else if (strcmp(option, "subtract") == 0) {
        result = sub(n1, n2);
    } else if (strcmp(option, "multiply") == 0) {
        result = mul(n1, n2);
    } else if (strcmp(option, "divide") == 0) {
        result = division(n1, n2);
    } else {
        printf("Invalid option.\n");
        return 1; // Exit with error code 1 for invalid option
    }

    // Display the result of the arithmetic operation
    printf("Result: %.1f + %.1fi\n", result.real, result.img);

    return 0;
}

// Function to add two complex numbers
complex add(complex n1, complex n2) {
    complex temp;
    temp.real = n1.real + n2.real; // Add real parts
    temp.img = n1.img + n2.img;    // Add imaginary parts
    return temp;
}

// Function to subtract two complex numbers
complex sub(complex n1, complex n2) {
    complex temp;
    temp.real = n1.real - n2.real; // Subtract real parts
    temp.img = n1.img - n2.img;    // Subtract imaginary parts
    return temp;
}

// Function to multiply two complex numbers
complex mul(complex n1, complex n2) {
    complex temp;
    temp.real = (n1.real * n2.real) - (n1.img * n2.img); // Multiply real parts and subtract product of imaginary parts
    temp.img = (n1.real * n2.img) + (n1.img * n2.real); // Multiply real part of first with imaginary part of second and vice versa, then add
    return temp;
}

// Function to divide two complex numbers
complex division(complex n1, complex n2) {
    complex temp;
    float denominator = pow(n2.real, 2) + pow(n2.img, 2); // Calculate the denominator
    temp.real = ((n1.real * n2.real) + (n1.img * n2.img)) / denominator; // Real part of division
    temp.img = ((n1.img * n2.real) - (n1.real * n2.img)) / denominator; // Imaginary part of division
    return temp;
}
