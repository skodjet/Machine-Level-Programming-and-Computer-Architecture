#include <stdio.h>

void increment(int *);

int sum_array(int[], int);
#define SIZE 20

int glob;

int main(int argc, char *argv[]) {

    //From 9/22
    int x = 975;

    printf("x: %d\n", x);
    increment(&x);
    printf("x: %d\n", x);

    //End from 9/22. Start from 9/27
    printf("&x: %p\n", &x); //%p prints the address
    printf("&glob: %p\n", &glob);
    //Notice that glob is higher up. This represents the structure of memory.

    printf("main: %p\n", main);

    int int_array[SIZE];

    for(int i = 0; i < SIZE; i++) {
        int_array[i] = i;
    }

    int sum = sum_array(int_array, SIZE);

    printf("Sum: %d\n", sum);


    char c[5];
    int i[5];
    printf("sizeof(c): %lu\n", sizeof(c)); //Prints number of BYTES c takes
    printf("sizeof(i): %lu\n", sizeof(i)); //Prints number of BYTES i takes
    printf("sizeof(sum): %lu\n", sizeof(sum)); //Prints the size of the variable "sum", NOT the value of "sum".

    printf("int_array[0]: %d\n", int_array[0]); //Originally was 0. Got changed to 50.


    printf("&Sum: %d\n", (&sum)[0]);

    return 0;
}

//From 9/22
void increment(int *a) {
    int y = *a; //Go to the address of a, and store the value stored there in variable y
    y++;
    *a = y; //Go to the address of a, and store the value of y at that address.
}

//End from 9/22. Start from 9/27

int sum_array(int *arr, int length) {
    int total = 0;

    int *ptr = arr;

    for(int i = 0; i < length; i++) {
        total += *ptr; //Add the value at *ptr to the total
        ptr++; //Increment the pointer within the array
    }


    

    return total;
}