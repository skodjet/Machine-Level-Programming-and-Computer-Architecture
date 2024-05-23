#include <stdio.h>
#include <stdlib.h>




struct time { 
    int hr;
    int min;
    int sec;
    char name[100];
};

struct time c; //data
struct time *d; //pointer in data, struct in heap


typedef int my_int;
typedef struct time time;

my_int x;




typedef struct Node {
    int value;
    struct Node *next;

}Node;


typedef struct {
    char c1;
    int i;
    char c3;
    short s;
} cci;

int main() {
    struct time a = {3, 27, 45, "Time name"}; //Stack
    a.hr = 15;
    printf("a time: %d:%02d:%02d\n", a.hr, a.min, a.sec);
    printf("sizeof(a): %lu\n", sizeof(a));

    //Pointer in stack, struct in heap
    struct time *b = (struct time*) malloc(sizeof(struct time));
    b -> hr = 15; //Need to dereference b to change its values.
    printf("b time: %d:%02d:%02d\n", b -> hr, b -> min, b -> sec);

    printf("a.hr = %d\n", a.hr);
    func(a);
    printf("a.hr = %d\n", a.hr);
    
    change_hr(&a);
    printf("a.hr = %d\n", a.hr);


    return 0;
}

void func(struct time var) {
    var.hr = 20;
    printf("var.hr = %d\n", var.hr);
}

void change_hr(struct time *var) {
    var -> hr = 20;
    printf("var -> hr %d\n", var -> hr);
}