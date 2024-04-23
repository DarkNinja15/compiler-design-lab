#include <stdio.h>

int main() {
    int num1;
    int num2;
    int sum ;
    
    // Input first number
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    // Input second number
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Calculate sum
    sum = num1 + num2;
    
    // Display the result
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    
    return 0;
}