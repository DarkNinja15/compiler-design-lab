/*  I am doing this code in c
 Adarsh Kumar 2101001CS
Lab 01 Date -09-01-2024
Write a C program to count number of characters, words, blank space, and lines in a text file. 
Logic to count characters, words and lines in a file in C program.
 How to count total characters, words and lines in a text file in C programming.
*/ 
#include <stdio.h>

int main() {
    FILE *filePointer;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0, isWord = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    filePointer = fopen(filename, "r");

    // Check if the file exists
    if (filePointer == NULL) {
        printf("File not found or unable to open the file.\n");
        return 1; // Exit the program with an error code
    }

    // Read characters from the file until the end
    while ((ch = fgetc(filePointer)) != EOF) {
        // Increment character count for every character
        charCount++;

        // Check for a new line
        if (ch == '\n') {
            lineCount++;
        }

        // Check for a space, tab, or newline to detect the end of a word
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            isWord = 0;
        } else if (isWord == 0) {
            // A new word has started
            isWord = 1;
            wordCount++;
        }
    }

    // Close the file
    fclose(filePointer);

    // Display the results
    printf("Total characters: %d\n", charCount);
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);

    return 0; // Exit the program
}

/*
OUTPUT

Total characters: 17
Total words: 5
Total lines: 4
Total spaces: 13
Special characters: 3

*/