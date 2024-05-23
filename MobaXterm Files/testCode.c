#include <stdio.h>

void testFunc(int *ptr);

void testFunc(int *ptr) {
    printf("%x\n", ptr);
    printf("%d\n", ptr);
    printf("%ls\n", ptr);

}


int main() {
    printf("%d", (-350 % 10));
    return 0;
}