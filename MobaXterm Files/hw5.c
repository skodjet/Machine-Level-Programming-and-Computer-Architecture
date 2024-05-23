#include <stdio.h>

int a = 86;  // numerator
short b = 11; // denominator
int q, r;
short ans;

// Sets the quotient q and remainder r for the integer division a/b (where b != 0)
int main(){
    q = 0;
    r = a;
    while (r >= b){
        q++;
        r = r - b;
    }

    ans = q;

    printf("%d\n", ans);
    printf("%d\n", r);
}