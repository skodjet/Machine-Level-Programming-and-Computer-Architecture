#include <stdio.h>

void increment(int*);

int main() {
    int x = 975;
    printf("x: %#06x\n", x);

    //***********Pointers****************
    int *var;
    

    //%p prints addresses, and &variableName returns the address of the variable.
    printf("&x: %p\n", &x);


    printf("x: %d\n", x);
    increment(&x);  //Pass the address of x to increment
    printf("x: %d\n", x);

    return 0;
}

void increment(int *a) {
    printf("a: %p\n", a);
    printf("&a: %p\n", &a);
    int y = *a;
    y++;
    *a = y;
}