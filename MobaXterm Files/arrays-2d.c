#include <stdio.h>
#include <stdlib.h>

int *x; //Created in data

int b[4][5];

int main(int argc, char *argv[]) {
    x = malloc(10); //x now points to the heap.
    free(x);

    //2D arrays
    int a[2][3]; //Created in the stack

    printf("a: %p\n", a);
    printf("a[0]: %p\n", a[0]);
    printf("a[1]: %p\n", a[1]);

    printf("\n");

    printf("b: %p\n", b);
    printf("b[0]: %p\n", b[0]);
    printf("b[1]: %p\n", b[1]);


    // int *c[2];
    // c[0] = (int*) malloc(3 * sizeof(int));
    // c[1] = (int*) malloc(3 * sizeof(int));
    //c[0] and c[1] are created in the heap (because of malloc()). int *c[2] is in the stack.

    int **c;
    c = (int**) malloc(2 * sizeof(int*));
    c[0] = (int*) malloc(3 * sizeof(int));
    c[1] = (int*) malloc(3 * sizeof(int));
    //Now only **c is in the stack. c points to c[0] and c[1], and c, c[0], and c[1] are all in the heap.

    printf("\n");
    printf("c: %p\n", c);
    printf("c[0]: %p\n", c[0]);
    printf("c[1]: %p\n", c[1]);

    c[1][1] = 10;
    printf("c[1][1]: %d\n", c[1][1]);

    return 0;
}