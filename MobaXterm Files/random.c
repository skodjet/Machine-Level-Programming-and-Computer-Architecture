#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("%d\n", rand());

    srand(2);

    for(int i = 0; i < 19; i++) {
        printf(", %d", rand());
    }
}