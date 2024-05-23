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

void push(int item);
int pop();
void free_stack();


typedef struct Node {
    int value;
    struct Node *next;
} Node;

int stackSize = 0; //The stack is initialized with size 0.
Node *topOfStack = NULL; //The top of the stack. Initially NULL.

void push(int item) { //Pushes item onto the stack by creating a new node with that value.
    if (stackSize == 0) { //Case for an empty stack.
        topOfStack = (Node *) malloc(sizeof(Node));
        topOfStack -> value = item;
        topOfStack -> next = NULL;

    } else {
        //Create the new node at the beginning of the linked list.
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode -> value = item;
        newNode -> next = topOfStack;

        //Update the top of the stack.
        topOfStack = newNode;
    }

    stackSize++;
}

int pop() { //Removes the item at the top of the stack and returns its value.
    if (stackSize <= 0) return 0; //No items in the stack, so return nothing.
        
    int returnValue = topOfStack -> value;

    //Update the top of the stack and delete the old top of the stack.
    Node *oldTopOfStack = topOfStack;
    topOfStack = oldTopOfStack -> next;
    oldTopOfStack -> next = NULL;
    free(oldTopOfStack);


    stackSize--;
}

void free_stack() { //Frees all memory related to the stack and resets the stack size.
    while (stackSize > 0) {

        //Traverse the linked list and delete each node.
        Node *temporary = topOfStack -> next;
        free(topOfStack);
        topOfStack = temporary;

        stackSize--;
    }
}
