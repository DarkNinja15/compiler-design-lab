/* Problem : Write a c program to add two real numbers with three variables including some comment lines in the program. Save the program as Add.c. Now read the program Add.c and display the count of the number of variables as a valid identifier. Count the number of comment lines in the code. and the number of statements in the program Add.c 


//I'm doing this problem in C language



*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE *fp;
    char line[256];
    int commentCount = 0, variableCount = 0, statementCount = 0;
    bool inCommentBlock = false;

    fp = fopen("add.c", "r");
    if (fp == NULL) {
        printf("Could not open file Add.c\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)){
        // Check for comment lines
        if (strstr(line, "//") != NULL) {
            commentCount++;
        }

        // Check for variables
        // This is a very simplified check and might not be accurate for complex scenarios
        if (strstr(line, "int ") != NULL || strstr(line, "float ") != NULL || strstr(line, "double ") != NULL) {
            // Assuming one variable declaration per line
            variableCount++;
        }

        // Check for statements
        // This check counts lines ending with ';' as statements and includes return statements
        if (strchr(line, ';') != NULL) {
            statementCount++;
        }
    }

    fclose(fp);

    printf("Number of comment lines: %d\n", commentCount);
    printf("Number of variables: %d\n", variableCount);
    printf("Number of statements: %d\n", statementCount);

    return 0;
}



// output
// Number of comment lines: 10
// Number of variables: 3 
// Number of statements: 8