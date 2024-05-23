#include <stdio.h>

#define BUFSZ 1024

int main() {
    //Arrays
    char c[12] = "Hello World!"; //Doesn't have space for the end character so it keeps printing.
    char d[100] = "This is some other statement!";
   // c[3] = 0; //This is the ASCII equivalent of the null character (tells C that this is the end of the string).


    printf("%s\n", c);

    return 0;
}