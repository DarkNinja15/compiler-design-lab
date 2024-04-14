/*  I am doing this code in c
 Adarsh Kumar 2101001CS
Lab 02 Date : 16-01-2024

*/ 
/* This program adds two real numbers and demonstrates reading from a file,
 * counting variables, comments, and statements.
 The program count the numbers of variables , comments and statements 
 this will be done by reading the file  */

#include <stdio.h>
#include <ctype.h>

int main() {
    // Open the file Add.c in read mode
    FILE *fp = fopen("Add.c", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int variables = 0, comments = 0, statements = 0;
    char line[100];

    // Read each line of the file
    while (fgets(line, sizeof(line), fp)) {
        // Count variables (assuming valid identifiers start with a letter and contain letters, digits, or underscores)
        for (int i = 0; line[i]; i++) {
            if (isalpha(line[i]) && !isalpha(line[i - 1])) {
                variables++;
                while (isalnum(line[i]) || line[i] == '_') {
                    i++;
                }
            }
        }

        // Count comment lines (both single-line and multi-line comments)
        if (line[0] == '/' && (line[1] == '/' || line[1] == '*')) {
            comments++;
        }

        // Count statements (assuming each statement ends with a semicolon)
        int semicolons = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] == ';') {
                semicolons++;
            }
        }
        statements += semicolons;
    }

    fclose(fp);

    printf("Number of variables: %d\n", variables);
    printf("Number of comment lines: %d\n", comments);
    printf("Number of statements: %d\n", statements);

    return 0;
}
/*
Output :
Enter the file name : 1001CS_add.c
Number of variables: 3 
Number of comment lines: 17
Number of statements: 11 
The file is opened and read successfully 
The number of variables , comment lines and statements are diaplayed successfully.
*/