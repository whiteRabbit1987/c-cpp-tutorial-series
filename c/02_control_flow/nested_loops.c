#include <stdio.h>

int main()
{

    // Nested loops =   A loop inside another loop, useful for repeated patterns
    //                  You can mix different loop types (e.g., a while loop containing a for loop)
    //                  This is helpful for tasks like grids, tables, or multi-level iterations



    // int rows = 0;
    // int cols = 0;
    // char symbol = '\0';

    // printf("Enter the number of rows: ");
    // scanf("%i", &rows);
    // printf("Enter the number of cols: ");
    // scanf("%i", &cols);
    // printf("Enter a symbol: ");
    // scanf(" %c", &symbol);

    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < cols; j++){
    //         printf("%c ", symbol);
    //     }
    //     printf("\n");
    // }


    // for(int i = 1; i <= 25; i++){
    //     for(int j = 1; j <= 25; j++){
    //         printf("%5d ", i * j);
    //     }
    //     printf("\n");
    // }


    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            printf("%3d ", i * j);
        }
        printf("\n");
    }

    // int count = 0;

    // while (count < 3){
    //     for (int i = 0; i < 10; i++){
    //         printf("%d ", i);
    //     }
    //     printf("\n");
    //     count++;
    // }

    // char symbol = '*';

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < i; j++){
    //         printf("%c", symbol);
    //     }
    //     printf("\n");
    // }

    return 0;
}