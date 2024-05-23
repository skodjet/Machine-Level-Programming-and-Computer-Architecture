#include <stdio.h>

int x; //This is a global variable :D

int sum(int a, int b) {
    x = a + b;
}


int main() {

    printf("%d\n", x);
    sum(3,5);
    printf("%d\n", x); //x changes here because it is global

    //***********SCANF

    //int i;

    //scanf("%d",  &i);

    //printf("i = %d\n", i);

    //int month, day, year;

    //printf("Please enter a date (mm/dd/yyyy): ");
    //scanf("%d/%d/%d", &month, &day, &year);

    //printf("Month: %d\n", month);
    //printf("Day: %d\n", day);
    //printf("Year: %d\n", year);


    //*********GETCHAR

    //char c = getchar(); //Takes in the first character you enter as c.
    //printf("c = %c\n", c);
    //c = getchar();
   // printf("c = %c\n", c);


    char array[100];
    int i = 0;
    char c;

    while((c = getchar()) != EOF) {
        array[i++] = c;
    }
    
    array[i] = '\0'; //Make sure the string ends with an end character!

    //printf("Array = %s\n", array);


    //Now let's use putchar() to print the sequence of characters.
    for(i = 0; array[i] != '\0'; i++) {
        c = putchar(array[i]);
        //Check if c is EOF (indicating error)
    }
    putchar('\n');




    return 0;
}
