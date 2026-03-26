/* write_text_file.c
 * writing a text file in C
 * purpose               = demonstrate basic file output using fopen/fprintf
 * fopen("w")            = creates or truncates the file
 * fprintf               = writes formatted text to the file
 * fclose                = closes the file and flushes buffers
 * best practice         = always check if fopen returned NULL
 */

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Couldn't open the file!\n");
        return 1;
    }

    float a = 4.333f;
    float b = 5.302f;

    fprintf(fp, "a = %.3f\n", a);
    fprintf(fp, "b = %.3f\n", b);
    fprintf(fp, "a + b = %.3f\n", a + b);
    fprintf(fp, "a * b = %.3f\n", a * b);

    fclose(fp);

    printf("File written successfully!\n");
    return 0;
}
