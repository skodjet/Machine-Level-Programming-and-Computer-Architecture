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

struct u {
    int *set;
    int len;
};


//Concatenates string s1 with string s2
char* cat(char* s1, char* s2) {
    int s1Chars = 0;
    int s2Chars = 0;

    //Count the number of characters in s1 and s2
    while(s1[s1Chars] != '\0') {
        s1Chars++;
    }

    while(s2[s2Chars] != '\0') {
        s2Chars++;
    }

    //The "+ 1" is space for the '/0' character.
    char *outputString = (char *) malloc((s1Chars + s2Chars + 1) * sizeof(char));

    //Put the characters from s1 and s2 into outputString.
    for(int j = 0; j < s1Chars; j++) {
        outputString[j] = s1[j];
    }

    int s2CharCounter = 0;

    for(int k = s1Chars; k < (s1Chars + s2Chars); k++) {
        outputString[k] = s2[s2CharCounter];
        s2CharCounter++;
    }

    //End the string.
    outputString[s1Chars + s2Chars] = '\0';

    return outputString;
}


//Performs the union of set1 and set2.
struct u* set_union(struct u *set1, struct u *set2) {
    int set1Current = 0;
    int set2Current = 0;
    int unionOffset = 0;
    int *unionSet = (int *) malloc((set1->len + set2->len) * sizeof(int));

    while((set1Current < set1->len) && (set2Current < set2->len)) {
        /*Take the smaller of the values from set1 and set2 and place it in unionSet.
          However, first make sure that value isn't in the set already.*/

        if((set1->set[set1Current] <= set2->set[set2Current]) //Take from set1
            && *(unionSet + (unionOffset-1)) != set1->set[set1Current]) {

            *(unionSet + unionOffset) = set1->set[set1Current];
            set1Current++;
            unionOffset++;

        } else if((set1->set[set1Current] > set2->set[set2Current]) 
          && (*(unionSet + (unionOffset-1)) != set2->set[set2Current])) { //Take from set2

            *(unionSet + unionOffset) = set2->set[set2Current];
            set2Current++;
            unionOffset++;
        

        //If the value is already in the set, just increment past the value and continue.
        } else if((set1->set[set1Current] <= set2->set[set2Current])
          && *(unionSet + (unionOffset-1)) == set1->set[set1Current]) {

                set1Current++;
            

        } else {
            set2Current++;
        }
    }

    //Put any remaining values that are not duplicates into the union.
    //Take the rest from set2.
    if(set1Current >= set1->len) {
        while(set2Current < set2->len) {
            if(*(unionSet + (unionOffset-1)) != set2->set[set2Current]) {

            *(unionSet + unionOffset) = set2->set[set2Current];
            set2Current++;
            unionOffset++;

            } else {
                set2Current++;
            }
        }

    //Take the rest from set1
    } else if(set2Current >= set2->len) {
        while(set1Current < set1->len) {
            if((*(unionSet + (unionOffset-1)) != set1->set[set1Current])) {

            *(unionSet + unionOffset) = set1->set[set1Current];
            set1Current++;
            unionOffset++;

            } else {
                set1Current++;
            }

        }
    }

    struct u *returnSet = (struct u*) malloc(sizeof(struct u));

    returnSet->len = unionOffset;
    returnSet->set = unionSet;


    return returnSet;
}

//Returns a 32-bit binary string of num using bitwise operations.
char *convert(int num) {

    //Need an extra space for '\0'
    char *conversion = (char *) malloc(33 * sizeof(char));
    int currentNum = num;

    // Checks if the leftmost bit of currentNum is a 1 or a 0.
    for(int j = 0; j < 32; j++) {
        currentNum = num << j;

        //-2147483648 is 1 followed by 31 zeros.
        if((currentNum | -2147483648) == currentNum) {
            *(conversion + j) = '1';
        } else {
            *(conversion + j) = '0';
        }

    }

    *(conversion + 32) = '\0';

    return conversion;

}


/*Constructs a 2D array of strings, with each new row appearing after
  a newline character. Stops when given EOF and returns the array.*/
char** lines(void) {
    char **outputArray;
    int startOfLine = 0;
    int numRows = 0;
    int charIndex = 0;
    char input = getchar();

    //Denotes the beginning of the input.
    char *allInput = (char *) malloc(sizeof(char));

    //Take the entire input
    while(input != EOF) {
        *(allInput + charIndex) = input;
        charIndex++;
        input = getchar();
    }

    /*Count the number of rows and allocate space for them in the 2D array.
      Each row ends with a '\n'.*/
    for(int i = 0; i < charIndex; i++) {
        if(*(allInput + i) == '\n') {
            numRows++;
        }
    }

    outputArray = (char **) malloc(numRows * sizeof(char *));

    int k = 0;
    for(int j = 0; j < numRows; j++) {

        //Place each line in an array.
        while(*(allInput + k) != '\n') {
            k++;
        }
        int rowLength = k - startOfLine;
        char *currentRow = (char *) malloc(k * sizeof(char));
        int l;
        for(l = 0; l < rowLength; l++) {
            *(currentRow + l) = *(allInput + startOfLine);
            startOfLine++;
        }
        *(currentRow + l) = '\0';
        startOfLine++;
        k++;



        //Place the line in the 2D array
        outputArray[j] = currentRow;

    }

    return outputArray;       

    
}


