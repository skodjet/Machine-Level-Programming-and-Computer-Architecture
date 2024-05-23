#include <stdio.h>

int main() {
    int arr[10];
    int *p1 = arr;
    int *p2 = &arr[4]; //p2 points to the 4th index of arr.

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);

    printf("p2 - p1: %ld\n", p2 - p1);

    if (p2 < p1) {
        printf("p1 is at a larger index\n");
    } else {
        printf("p2 is at a larger index");
    }

    arr[0] = 5;
    arr[2] = 17;
    printf("arr[0: %d\n", arr[0]);
    printf("*arr: %d\n", *arr);
    printf("*(arr + 2): %d\n", *(arr + 2));

    return 0;
}