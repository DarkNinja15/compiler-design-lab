/* Write a C program to count number of characters, words, blank space, and lines in a text file. Logic to count characters, words and lines in a file in C program. How to count total characters, words and lines in a text file in C programming. 

i'm doing this code in c    */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    char path[100];
    char ch;
    int characters, words, lines;
    file = fopen("counting.txt", "w");
   printf("enter the text.press cntrl Z:");
   while((ch = getchar())!=EOF){
        putc(ch, file);
   }
   fclose(file);
   printf("Enter source file path: ");
   scanf("%s", path);
   file = fopen(path, "r");
   if (file == NULL){
      printf("Unable to open file.");
      exit(EXIT_FAILURE);
   }
   characters = words = lines = 0;
   while ((ch = fgetc(file)) != EOF){
        characters++;
   // if (ch == ' ' || ch == '\0')
   //    lines++;
   if (ch == ' ' || ch == '\t' || ch == ' ' || ch == '\0')
      words++;
   }
   if (characters > 0){
        words++;
        lines++;
   }
   printf("");
   printf("Total characters = %d ", characters);
   printf("Total words = %d ", words);
   printf("Total lines = %d ", lines);
   fclose(file);
   return 0;
}


// output
// Enter the filename: counting.txt
// Total characters: 33
// Total words: 5
// Total blank spaces: 6
// Total lines: 6