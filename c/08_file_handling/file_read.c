/* read_text_file.c
 * reading a text file in C
 * purpose               = demonstrate basic file input using fopen/fgets
 * fopen("r")            = opens file for reading
 * fgets                 = reads one line at a time into a buffer
 * feof                  = only true *after* a failed read
 * best practice         = check fopen result and read using fgets loop
 */

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "r");   // open file for reading ("r" = read mode)

    if (fp == NULL) {                      // fopen returns NULL if file doesn't exist
        printf("Couldn't open the file!\n");
        return 1;
    }

    char buffer[256];                      // buffer to store each line (fixed-size)

    // fgets reads up to sizeof(buffer)-1 chars or until newline
    // returns NULL when no more lines can be read
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);              // print the line exactly as read
    }

    fclose(fp);                            // always close the file

    printf("\nFile read successfully!\n");
    return 0;
}
