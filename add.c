//Q.2 Write tail recursive definition of fibonachi series function in c, compile, run, check output, save as TRDF.c.
// Now read the code in other c program to count no of tokens, Identifier, and operater in TRDF.c file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/%=<>!";
    for (int i = 0; i < strlen(operators); i++){
        if (ch == operators[i]) {
            return 1; // It is an operator
        }
    }
    return 0; // It is not an operator
}

int main() {
    FILE *file;
    char filename[] = "TRDF.c";
    char buffer[1000];
    char *token;
    int tokenCount = 0, identifierCount = 0, operatorCount = 0;

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Tokenize the line
        token = strtok(buffer, " \t\n");

        // Process each token
        while (token != NULL) {
            tokenCount++;

            // Check if the token is an identifier
            if ((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')) {
                identifierCount++;
            }

            // Check if the token is an operator
            if (strlen(token) == 1 && isOperator(token[0])) {
                operatorCount++;
            }

            // Get the next token
            token = strtok(NULL, " \t\n");
        }
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("Total Tokens: %d\n", tokenCount);
    printf("Total Identifiers: %d\n", identifierCount);
    printf("Total Operators: %d\n", operatorCount);

    return 0; // Exit successfully
}