//Q.2 Write tail recursive definition of fibonachi series function in c, compile, run, check output, save as TRDF.c.
// Now read the code in other c program to count no of tokens, Identifier, and operater in TRDF.c file

#include <stdio.h>

// Tail Recursive Definition of Fibonacci Series
int fib(int n, int a, int b) {
    if (n == 0)
        return a;
    else
        return fib(n - 1, b, a + b);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fib(n, 0, 1));

    return 0;
}