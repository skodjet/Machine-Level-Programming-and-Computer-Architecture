#include <stdio.h>

int main() {
    // Integers
    char c;     //size: 1 byte
    short s;    //size: >= 2 bytes
    int i;      //size: >= 2 bytes
    long l;
    long long ll;

    sizeof(int);
    
    printf("char: %ld\n", sizeof(char)); //Has to be ld and not d because sizeof() returns a long integer.
    printf("short: %ld\n", sizeof(short));
    printf("int: %ld\n", sizeof(int));
    printf("long: %ld\n", sizeof(long));
    printf("long long: %ld\n", sizeof(long long)); 

	//Float size is 4
	//Double size is 8
	//long double size is 16
    
    

    return 0;
}