#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 2
#define COLS 3

int main() {
    // char *arr = (char*) malloc(10 * sizeof(char));

    // strcpy(arr, "Hello"); //Copies "Hello" into arr


    // printf("arr: %p\n", arr);
    // printf("arr: %s\n", arr);
    // free(arr);

    // printf("arr: %p\n", arr);
    // printf("arr: %s\n", arr);

    // arr = (char*) malloc(100 * sizeof(char));

    // strcpy(arr, "This is a much longer string for a larger buffer!");
    // printf("arr: %s\n", arr);
    // free(arr);

    // int a[ROWS][COLS];
    // printf("a: %p\n", a);
    // printf("a[0]: %p\n", a[0]);
    // printf("a[1]: %p\n", a[1]);
    // printf("a[1][0]: %p\n", &a[1][0]);

    // int **a = (int**) malloc(ROWS * sizeof(int*));
    // for(int i = 0; i < ROWS; i++) {
    //     a[i] = (int*) malloc(COLS * sizeof(int));
    // }


    // for(int i = 0; i < ROWS; i++){
    //     for(int j = 0; j < COLS; j++) {
    //         a[i][j] = 1 + i + j;
    //     }
    // }

    // for(int i = 0; i < ROWS; i++) {
    //     printf("Row %d:\t", i);
    //     for(int j = 0; j < COLS; j++) {
    //         printf("%4d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("a[0]: %p\n", a[0]);
    // a[0] = realloc(a[0], 50000);
    // printf("a[0]: %p\n", a[0]);

    // for(int i = 0; i < 5; i++) {
    //     printf("%4d ", a[0][i]);
    // }


    // //OR we can do this (manual, while the for loop is easier).
    // // a[0] = (int*) malloc(COLS * sizeof(int));
    // // a[1] = (int*) malloc(COLS * sizeof(int));

    // for(int i = 0; i < ROWS; i++) {
    //     free(a[i]);
    // }
    // free(a);

    // ********************February 9th**************************

    int b[2][4];
    printf("b[0] = %p\n", b[0]);
    printf("b[1] = %p\n", b[1]);
    printf("b[2] = %p\n", b[2]);



    return 0;
}