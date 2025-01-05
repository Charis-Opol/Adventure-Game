#include <stdio.h>

// Function declaration
void findGCD();

// Main function
int main() {
    findGCD(); // Call the function to find the GCD
    return 0;
}

// Function definition
void findGCD() {
    int num1, num2; // Variables to store user input

    // Prompt the user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Store original numbers for display later
    int originalNum1 = num1;
    int originalNum2 = num2;

    // Euclidean algorithm to find GCD
    while (num2 != 0) {
        int remainder = num1 % num2; // Calculate the remainder
        num1 = num2;                // Assign num2 to num1
        num2 = remainder;           // Assign remainder to num2
    }

    // Display the result
    printf("The GCD of %d and %d is: %d\n", originalNum1, originalNum2, num1);
}
