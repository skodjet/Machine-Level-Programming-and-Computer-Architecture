#include <stdio.h>
#include <stdlib.h>

int* sum_rows(int arr[][3], int nrows);

int main() {
    int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int *sum = sum_rows(arr, 2);
    for(int i = 0; i < 2; i++) {
        printf("arr[%d] = %d\n", i, sum[i]);
    }

    return 0;
}

int* sum_rows(int arr[][3], int nrows){ //Returns a 1d array. nrows is number of rows.
    int *totals = (int*)(malloc(sizeof(int) * nrows)); //Allocates 4 bytes for each integer in the array we want to return.

    int i = 0, j = 0;
    for(int i = 0; i < nrows; i++) {
        for(j = 0; j < 3; j++) {
            totals[i] += arr[i][j];
        }
    }

    return totals; //DANGER: totals is created in the stack, so when the function ends, totals is deleted.

}