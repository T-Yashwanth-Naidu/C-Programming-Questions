/*Define a structure to represent a 3D point in space. Write functions to calculate the distance between two points.

WTD: Design a structure to model a 3D point in space. Develop functions that calculate the Euclidean distance between any two given points using the standard distance formula.
Use Distance formula D= Sqrt( (x2-x1)^2  + (y2-y1)^2  + ( z2-z1)^2))

(e.g: I/P P1(1.0,2.0,3.0), P2(4.0,6.0,8.0); O/P is Distance= 7.071 )*/

#include <stdio.h>
#include <math.h>

// Define a structure for a point in 3D space
struct Point {
    float x; // x-coordinate
    float y; // y-coordinate
    float z; // z-coordinate
};

int main() {
    // Define two points p1 and p2
    struct Point p1 = {1.0, 2.0, 3.0}; // Point 1 coordinates
    struct Point p2 = {4.0, 6.0, 8.0}; // Point 2 coordinates
    
    // Calculate the distance using the Euclidean distance formula
    float distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) + pow((p2.z - p1.z), 2));
    
    // Print the calculated distance with 3 decimal places
    printf("Distance = %.3f\n", distance);

    return 0;
}