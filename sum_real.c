

#include <stdio.h>

int main() {
    // Declare variables to store the numbers and their sum
    float num1, num2, sum;

    // Prompt the user to enter the first number
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Prompt the user to enter the second number
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Calculate the sum of the two numbers
    sum = num1 + num2;

    // Print the sum to the console
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, sum);

    return 0;
}
