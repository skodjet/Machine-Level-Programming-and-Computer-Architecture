//Name: Tommy Skodje
//email: tommy.skodje@emory.edu
//student ID: 2447760
/*
THIS CODE WAS MY OWN WORK , IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. Tommy Skodje
*/

#include <stdio.h>

void fib(int n) { //Prints out the first n fibonacci numbers
    int numToPrint;

    //Base cases for fibonacci numbers. First two numbers of the sequence.
    int previousNum = 1;
    int secondPreviousNum = 1;

    for(int i = 0; i < n; i++) {
        if(i == 0 || i == 1) {
           if(i != n-1) { 
                printf("1, ");
           } else { //Case for if 1 is the only value to be printed.
                    //Don't want the comma and space if this is the case.
                printf("1");
           }
        } else {
            numToPrint = previousNum + secondPreviousNum;
            if(i != n-1) {
                printf("%d, ",numToPrint);
            } else { //If this is the last number to print, don't print  
                     //the comma and space after.
                printf("%d", numToPrint);
            }

            //Updating the values
            secondPreviousNum = previousNum;
            previousNum = numToPrint;
        }
    } 
    putchar('\n');
}

void reverse(char *s) { //Prints the string s, then prints it in 
                        //reverse order on a new line.
    int counter = 0;

    //Counts how much space to allot for the string.
    for(int i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
        counter++;
    }

    putchar('\n');
    counter--; //This is needed because the counter is currently pointing to the stop character

    //Prints the string in reverse order.
    while(counter >= 0) {
        putchar(s[counter]);
        counter--;
    }

    putchar('\n');
}

void factors(long num) { //Prints the prime factors of num with repetition.
    if(num == 1) return; //Don't print anything for 1.


    while(num != 1) {
        for(int i = 2; i < num; i++) { //Loop through from 2 to num until a factor is found and print it.
                                       //Since we print the smallest factors first, all of the factors will be prime.                                       
            if((num % i) == 0) {
                printf("%d, ", i);
                num /= i;
                i = 1;
            }
        }
        printf("%ld",num); //Print the final factor and set num = 1 so the while loop is ended.
        num = 1;
    }

    putchar('\n');
}

void arithmetic(void) { //Allows the user to perform addition, subtraction, multiplication, 
                        //and division with remainders. Continually prompts the user for input
                        //until the EOF is received.
    int num1;
    int num2;
    int check; //Checks to see if scanf() has received the EOF.
    char operation;
    char input;


    printf("Operation: ");
    check = scanf("%d %c %d", &num1, &operation, &num2);


    while(check != EOF) { //Keep prompting the user for input until the EOF is received.

        switch(operation) { //Addition, subtraction, and multiplication are all implemented simply with the C 
                            //built-in operators.
            case '+':
                printf("Sum: %d", num1 + num2);
                break;
            case '-':
                printf("Difference: %d", num1 - num2);
                break;
            case '*':
                printf("Product: %d", num1 * num2);
                break;
            case '/': ;
                int remainder;
                if(num1 > 0) { //For positive numbers, remainder is just the value of modulo for the two inputs.
                    remainder = num1 % num2;
                    printf("Quotient: %d\nRemainder: %d", num1 / num2, remainder);

                } else { //For negative numbers, the quotient needs to be one less than "normal".
                         //Also, the remainder needs to be changed to be positive and between 0 
                         //and the denominator.
                    remainder = (num1 % num2) + num2;
                    printf("Quotient: %d\nRemainder: %d", (num1 / num2) - 1, remainder);
                } 

                break;
            
        }

        putchar('\n');

        printf("Operation: ");
        check = scanf("%d %c %d", &num1, &operation, &num2);

    }
}