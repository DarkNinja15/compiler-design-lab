/* Problem : Write a c program to add two real numbers with three variables including some comment lines in the program. Save the program as Add.c. Now read the program Add.c and display the count of the number of variables as a valid identifier. Count the number of comment lines in the code. and the number of statements in the program Add.c 


//I'm doing this problem in C language  
*/

#include <stdio.h>

int main() {
    // Declare three floating-point variables
    float num1, num2, sum;

    // Input two real numbers
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    // Add the two numbers
    sum = num1 + num2;

    // Display the sum
    printf("Sum = %.2f", sum);

    return 0; // End of the program
}


// output
// Enter first number: 1
// Enter second number: 2
// Sum = 3.00