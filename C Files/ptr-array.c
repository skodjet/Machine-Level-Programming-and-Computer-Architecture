#include<stdio.h>
#include<stdlib.h>

void array_func(int x[10], int);
void ptr_func(int *, int);


int main() {
    int x;
    int y[20];
    int *z = (int*) malloc(30 * sizeof(int));

    ptr_func(y, 20);
    ptr_func(z, 20);
    ptr_func(&x, 1);

    print_array(y, 20);
    print_array(z, 30);
    print_array(&x, 20);

    return 0;
}


void array_func(int x[10], int len) {
    for(int i = 0; i < len; i++) {
        x[i] = 2 * x[i];
    }
}

void ptr_func(int *ptr, int len) {
    int *p = ptr;
    for(int i = 0; i < len; i++) {
        *p = i; //Change the value at the pointer to i
        p++; //Increment the pointer
    }
}

void print_array(int *ptr, int len) {
    int *p = ptr;
    printf("%d", *p);
    p++;
    for(int i = 1; i < len; i++) {
        printf(", %d", *p);
        p++;
    }
    printf("\n");
}