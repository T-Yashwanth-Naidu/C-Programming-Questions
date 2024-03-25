/* Design a structure for an employee with an embedded structure for address (street, city, state, zip). ( Nested Structure)

WTD: Within this structure, embed another structure specifically meant for the employee's address details, capturing street, city, state, and zip code. Ensure capabilities to extract and display this address in a coherent format.

(e.g: I/P: Name: "Bob", Address: [Street: "456 Maple Rd", City: "Brookfield", State: "WI", Zip: "53005"]; O/P: Address: 456 Maple Rd, Brookfield, WI, 53005)
 */

#include <stdio.h>

// Define a nested structure for Address
struct Address {
    char street[100]; // Street address
    char city[100]; // City name
    char state[100]; // State name
    int zip; // ZIP code
};

// Define the Employee structure with a nested Address structure
struct Employee {
    char name[50]; // Employee name
    struct Address addr; // Address of the employee
};

int main() {
    // Create an instance of struct Employee and initialize it
    struct Employee emp = {"Bob", {"456 Maple Rd", "Brookfield", "WI", 53005}};
    
    // Print the address information using the nested structure
    //printf("Employee Name: %s\n", emp.name);
    printf("Address: %s, %s, %s, %d\n", emp.addr.street, emp.addr.city, emp.addr.state, emp.addr.zip);

    return 0;
}