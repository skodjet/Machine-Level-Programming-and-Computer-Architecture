//Name: Tommy Skodje
//Email: tommy.skodje@emory.edu
//User ID: TSKODJE
//Student ID Number: 2447760
/*
THIS CODE WAS MY OWN WORK , IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. Tommy Skodje
*/

#include <stdio.h>
#include <stdlib.h>

int sizeOfStack = 0; //The current size of the stack.
int numItems = 0; //The current number of items in the stack.
int *stack; //The actual stack where items will be pushed and popped.


void push(int item) { //Pushes item onto the top of the stack, and resizes the stack if it's full.

    if (sizeOfStack == 0) { //Allocate memory for an array if the stack is empty.
        stack = (int*) malloc(sizeof(int));
        sizeOfStack = 1;
    }

    numItems++;

    if (numItems >= sizeOfStack) { //Array is filled. Double the stack size and copy the values over.
        stack = (int*) realloc(stack, 2 * sizeOfStack * sizeof(int));
        sizeOfStack *= 2;
    }
    
    stack[numItems - 1] = item; //Push the item onto the stack.
}


int pop() { //Removes the top item from the stack, and returns its value.
    if (numItems <= 0) return 0; //No items in the stack, so return nothing.
    
    numItems--;

    int returnValue = stack[numItems]; //Store the popped value.


    if (4 * numItems <= sizeOfStack) { /*If the number of items in the stack is 
                                        <= 25% of the size of the stack, halve the 
                                        array size.*/

        stack = (int*) realloc(stack, (sizeOfStack / 2) * sizeof(int));
        sizeOfStack /= 2;
    } 

    return returnValue;
}


void free_stack() { //Frees stack memory and resets the size of the stack and number of items.
        free(stack);
        sizeOfStack = 0;
        numItems = 0;
    }