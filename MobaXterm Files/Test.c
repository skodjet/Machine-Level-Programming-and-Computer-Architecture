#include <stdio.h>
#include <stdlib.h>


// //Returns a 32-bit binary string of num using bitwise operations.
// char *convert(int num) {

//     //Need an extra space for '\0'
//     char *conversion = (char *) malloc(33 * sizeof(char));
//     int currentNum = num;

//     for(int j = 0; j < 32; j++) {
//         currentNum = num << j;

//         /*Determines whether the leftmost bit of
//           currentNum is a 1 or a 0, and fills in 
//           conversion accordingly. */
//         if((currentNum | -2147483648) == currentNum) {
//             *(conversion + j) = '1';
//         } else {
//             *(conversion + j) = '0';
//         }

//     }

//     *(conversion + 32) = '\0';

//     return conversion;

// }

//TODO: DELETE MAIN BEFORE SUBMITTING
int main() {

   cat("", "");
   char *ans = cat("Hello", "World");
   for(int i = 0; i < 10; i++) {
        printf("%c", ans[i]);
   }
   

    struct u x;
    struct u y;
    int set1[] = {2, 4, 5};
    int set2[] = {1, 3, 9 ,9, 9};
    x.set = set1;
    y.set = set2;
    x.len = 3;
    y.len = 5;
    struct u *a = &x;
    struct u *b = &y;

    struct u *c = set_union(a, b);

    for(int i = 0; i < c->len; i++) {
        printf("%d, ", *(c->set + i));
    }

    
    char *answer = convert(-1);
    for(int i = 0; i < 32; i++) {
        printf("%c", answer[i]);
    }

    char **a = lines();

    return 0;
}


