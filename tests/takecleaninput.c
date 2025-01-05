#include <stdio.h>
#include <stdlib.h>

// Function prototype with correct return type
int MAX_FUN(int num1, int num2); 

int main() {
    int num1, num2;

    printf("Enter the numbers you want to compare:\n");

    // Validate the first input
    printf("Enter first number:\n");
    while (scanf("%d", &num1) != 1) {
        printf("Invalid input. Please enter a valid number:\n");
        while (getchar() != '\n'); // Clear the input buffer
    }

    // Validate the second input
    printf("Enter second number:\n");
    while (scanf("%d", &num2) != 1) {
        printf("Invalid input. Please enter a valid number:\n");
        while (getchar() != '\n'); // Clear the input buffer
    }

    // Call the MAX_FUN function and store the result
    int maxResult = MAX_FUN(num1, num2);

    printf("The maximum number is: %d\n", maxResult);
    return 0;
}

// Function definition with correct return type and comments
int MAX_FUN(int num1, int num2) {
    // Determine the maximum number
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}