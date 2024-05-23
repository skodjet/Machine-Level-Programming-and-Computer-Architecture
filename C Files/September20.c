#include <stdio.h>

int main() {
    //From September 15

    // unsigned char c = 255;
    // printf("c: %d\n", c);
    // c++;
    // printf("c: %d\n", c);

    //char c = 3434; //Character overflow :O
    //printf("c: %d\n", c);

    //End code from September 15

    
    char c = 0x67; //Hexadecimal literal
    printf("c: %d\n", c); //print as number (decimal)
    printf("c: %c\n", c); //print as character (ASCII)
    printf("c: %x\n", c); //print as hex (without 0x)

    c = 0b00101101; //Binary literal
    printf("c: %d\n", c); //Print as number (decimal)

     float x = 0.15;
    printf("a: %.9f\n", x);
    printf("a: %.9e\n", x);
    printf("a: %.9g\n", x);

    //If you divide a float by 0 you get inf or -inf
    //If you take sqrt(-1) you get NaN (not a number)

    return 0;
}