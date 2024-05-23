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

void sort(int *arr, int len);
void quicksort(int *arr, int lower, int upper);
int rearrange(int *arr, int left, int right);
int randomizedRearrange(int *arr, int left, int right);


void sort (int *arr, int len) { //Sorts array arr with length len using quicksort.

    if(len > 1) {
    
        int lower = 0;
        int upper = len - 1;
        
        quicksort(arr, lower, upper); //Initially call quicksort on the entire array
    }
}



void quicksort(int *arr, int lower, int upper) { /*The recursive function that sorts the array between
                                                   the bounds of "lower" and "upper".*/

    if (lower < upper) {
        int pivotAddress = randomizedRearrange(arr, lower, upper); //Place the pivot in the correct location.
        quicksort(arr, lower, pivotAddress - 1); //Recursively run quicksort on the items to the left of the pivot.
        quicksort(arr, pivotAddress + 1, upper); //Recursively run quicksort on the items to the right of the pivot.
    }


}

int randomizedRearrange(int *arr, int left, int right) { /* swaps the left element
                                                            with a random element,
                                                            then returns the result
                                                            from the rearrange funciton */

    //Generate a random number between left and right
    int random = left + (rand() % (right - left + 1));

    //Swap the left element with the random element.
    int *randomAddress = arr + random; 
    int *leftAddress = arr + left;

    int temporary = *randomAddress;
    *randomAddress = *leftAddress;
    *leftAddress = temporary;

    return rearrange(arr, left, right);


}

int rearrange(int *arr, int left, int right) { /*Rearranges the array around the pivot element.
                                                  and returns the location of the pivot*/
    int pivotValue = *(arr + left); //Set the pivot as the value of the left element.
    int a = left + 1;
    int b = left + 1;


    for(b; b <= right; b++) {

        if(*(arr + b) <= pivotValue) { //If b < pivotValue, swap a and b, then increment a.
            int *aAddress = arr + a; //Address of the first number to be swapped.
            int *bAddress = arr + b; //Address of the second number to be swapped
            
            int temporary = *aAddress; //Temporarily save the value at the a address.
            *aAddress = *bAddress;
            *bAddress = temporary;

            a = a + 1;
        }
    }

    int *aAddress = arr + (a - 1);
    int *pivotAddress = arr + left; /*The index of the pivot in its correct location that 
                                    will be returned.*/
    
    //Swap the pivot with the the value at a.
    int temporary = *aAddress;
    *aAddress = *pivotAddress;
    *pivotAddress = temporary;    

    return a - 1;
}