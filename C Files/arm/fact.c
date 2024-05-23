#include <stdio.h>

int fact(int n) {
    int temp = 1;

    if (n == 0 || n == 1) {
        return temp;
    }

    temp = n * fact(n - 1);
    return temp;
}

int main() {
    fact(4);
    return 0;
}