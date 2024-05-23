#include<stdio.h>
int gcd(int, int);
int rem(int, int);

int ans;

int main(){
    ans = gcd(70, 20);
    printf("ans: %d\n", ans);
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    
    int r = rem(a, b);
    return gcd(b, r);
}

int rem(int a, int b){
    int q = 0;
    int r = a;
    while (r >= b){
        q++;
        r = r - b;
    }
    return r;
}