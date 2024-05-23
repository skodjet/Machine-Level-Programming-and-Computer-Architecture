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



int round(double num) { //Rounds the double "num" to the nearest integer.
    int roundedValue; //Return value

    //Get the values to the left and to the right of the decimal point.
    int nonFractionalValue = (int)num; 
    double fractionalValue = num - nonFractionalValue;

    if (num >= 0) { //For positive numbers
        if (fractionalValue >= 0.5) { //Round up if the fractional part of num is >= 0.5
            roundedValue = nonFractionalValue + 1;
        } else { //Round down if the fractional part of num is < 0.5
            roundedValue = nonFractionalValue;
        }
    } else { //For negative numbers

        /*Round down this time since num is negative. The OR case is necessary for
          numbers between -1 and 0*/
        if (fractionalValue >= 0.5 || fractionalValue <= -0.5) {
            roundedValue = nonFractionalValue - 1;
        } else { //Round up
            roundedValue = nonFractionalValue;
        }
    }

     return roundedValue;

}


int len(char *string) { //Returns the length of string.
    int stringLength = 0;
    char *currentChar = string; //Points to the current character. Initially the first character.

    while(*currentChar != '\0') { //Break the loop when the end of the string is reached.
        stringLength++;
        currentChar = string + stringLength; //Update the pointer.
    }

    return stringLength;

}


char *lower(char *string) { //Returns a copy of string without any capital letters.

    //Create a new string that is a copy of the input string.
    char *newString = (char *) malloc(len(string) * sizeof(char));
    int i = 0;
    //Copy the string over
    for(i = 0; i < len(string); i++) {
        *(newString + i) = *(string + i);
    }

    //Signify that this is the end of the string.
    *(newString + i) = '\0';

    

    char *currentChar = newString; //The current character in the new string.
    int offset = 0; //For looping through the new string.

    while(*currentChar != '\0') {

        /*Characters with ASCII codes between 65 and 90 are capital letters.
          Their lowercase counterparts are their ASCII codes + 32*/
        if((*currentChar >= 65) && (*currentChar <= 90)) {
            *currentChar = *currentChar + 32;
        }
        offset++;
        currentChar = newString + offset;
    }

    return newString;
}


void scramble(int **arr, int rows, int cols) { //Randomly rearranges the rows in arr.

    for(int i = 0; i < rows; i++) {
        int exchange = rand() % rows; //The row to exchange the current row with.

        //The first element in the current row.
        int *currentRow = arr[i];
        //The first element in the row to be exchanged with.
        int *exchangeRow = arr[exchange]; 

        int *temp = (int *) malloc(cols * sizeof(int));

        for(int j = 0; j < cols; j++) { //Copy the current row to temp
            *(temp + j) = *(currentRow + j);
        }

        //Copy exchangeRow to currentRow and temp to exchangeRow
        for(int k = 0; k < cols; k++) {
            *(currentRow + k) = *(exchangeRow + k);
            *(exchangeRow + k) = *(temp + k);
        }


        free(temp);

    }

}

char *convert(int num) { //Returns a string representation of num.

    if (num == 0) { //Special case if num is 0.
        char *output = (char *) malloc(2 * sizeof(char));
        output[0] = '0';
        output[1] = '\0';
        return output; 
    }

    int length = 0; //The length of num.
    int copy = num;
    char *output;

    while(copy != 0) { //Find the length of num.
        length++;
        copy = copy / 10;
    }

    if (num > 0) { //For positive numbers.

        //Create an output array that can store the number and '\0'
        output = (char *) malloc((length * sizeof(char)) + sizeof(char));
        output[length] = '\0';

        int currentPlace = length - 1;

        while(num > 10) {
            int lastDigit = num % 10; //Get the last digit of num

            //The ASCII values for numbers start at 48, so add 48 to the last digit.
            char valueToAppend = (char) (lastDigit + 48);

            //Append the char to the end of output.
            output[currentPlace] = valueToAppend;
            num = num / 10;
            currentPlace--;
        }

        //Append the final digit.
        output[currentPlace] = (char) (num + 48);

    } else { //For negative numbers

        //Create an output array that can store the number, a negative sign, and '\0'
        output = (char *) malloc((length * sizeof(char)) + (2 * sizeof(char)));
        output[length + 1] = '\0';

        int currentPlace = length;

        num = num - (2 * num); //Convert num to its absolute value

        while(num > 10) { //Same process as for positive numbers
            int lastDigit = num % 10;
            char valueToAppend = (char) (lastDigit + 48);
            output[currentPlace] = valueToAppend;
            num = num / 10;
            currentPlace--;
        }

        output[currentPlace] = (char) (num + 48);
        currentPlace--;
        output[currentPlace] = '-'; //Add the negative sign.
    }
    

    return output;
}



void binary(char num, int len) { /*Prints the binary representation of num
                                   with len number of bits to represent it.*/
    int *str = (int *) malloc(len * sizeof(int) + 1);
    str[len] = '\0';

    int currentPlace = len - 1;

    for(int i = 0; i < len; i++) { //Set all values in str to 0
        str[i] = 0;
    }
    if (num >= 0) { //For positive numbers and 0.
        while(num != 0) {
            /*Continuously divide by 2. If the remainder is 1, 
              set the current bit to 1.*/
            if (num % 2 == 1) {
                str[currentPlace] = 1;
            }

            num = num / 2;
            currentPlace--;
        }
    } else { //For negative numbers.
        num = num - (2 * num); //Get the absolute value of num.

        while(num != 0) { //Same process as for positive numbers.
            if (num % 2 == 1) {
                str[currentPlace] = 1;
            }

            num = num / 2;
            currentPlace--;
        }

        //Flip all the bits.
        for(int i = 0; i < len; i++) {
            if(str[i] == 0) {
                str[i] = 1;
            } 
            else {
                str[i] = 0;
            } 
        }

        //Add 1.
        int carry = 1;
        currentPlace = len - 1;
        while (carry == 1) {
            if (str[currentPlace] == 0) { //Current bit is 0. Set it to 1 and stop.
                str[currentPlace] = 1;
                carry = 0;
            } else { //Current bit is 1. Set it to 0 and keep going!
                str[currentPlace] = 0;
            }
            currentPlace--;
        }

    }


    //Print the binary number.
    for(int i = 0; i < len; i++) {
        printf("%d", *(str + i));
    }
    printf("\n");

    free(str);

}