/* Define a structure for a student with name, roll number, and marks in 5 subjects. Calculate the average marks for a list of students. ( Structure with Arrays).

WTD: Construct a structure that encapsulates a student's details, specifically their name, roll number, and scores in five subjects. Implement a function that computes the average marks for an array of student structures.

(e.g: I/P: Name: "Alex", Roll: 105, Marks: [75, 80, 88, 82, 86]; O/P: Avg Marks: 82.2) */

#include <stdio.h>

// Define the structure Student
struct Student {
    char name[100]; // Name of the student
    int roll_no; // Roll number of the student
    float marks[5]; // Array to store marks of 5 subjects
};

int main() {
    // Create an instance of struct Student and initialize it
    struct Student s1 = {"Alex", 105, {75, 80, 88, 82, 86}};

    // Calculate the size of the marks array using sizeof operator
    int size = sizeof(s1.marks) / sizeof(float);

    // Initialize a variable to store the sum of marks
    float sum = 0;

    // Iterate through the marks array and calculate the sum of marks
    for (int i = 0; i < size; i++) {
        sum += s1.marks[i];
    }

    // Calculate the average marks
    float avg = sum / size;

    // Print the average marks
    printf("Average marks for %s (Roll No: %d): %.1f\n", s1.name, s1.roll_no, avg);

    return 0;
}
