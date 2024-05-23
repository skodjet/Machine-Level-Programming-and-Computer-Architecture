#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 2
#define COLS 3

int main() {

    // ********************February 9th**************************

    int *a[2];
    a[0] = (int*) malloc(3*sizeof(int));
    a[1] = (int*) malloc(3*sizeof(int));

    for(int i = 0; i< 2; i++) {
        for(int j = 0; j < 3; j++) {
            a[i][j] = i + j + 1;
        }
    }

    for(int i = 0; i< 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    int b[2][4];
    printf("b[0] = %p\n", b[0]);
    printf("b[1] = %p\n", b[1]);
    printf("b[2] = %p\n", b[2]);



    return 0;
}