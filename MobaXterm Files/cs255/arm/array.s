//Name: Tommy Skodje
//Email: tommy.skodje@emory.edu
//User ID: TSKODJE
//Student ID Number: 2447760
/*
THIS CODE WAS MY OWN WORK , IT WAS WRITTEN WITHOUT CONSULTING ANY
SOURCES OUTSIDE OF THOSE APPROVED BY THE INSTRUCTOR. Tommy Skodje
*/

.global main

main:

WHILE:
    @ Load i and len
    movw r1, #:lower16:i
    movt r1, #:upper16:i
    ldr r1, [r1] @ r1 = i

    movw r0, #:lower16:len
    movt r0, #:upper16:len
    ldr r2, [r0] @ r2 = len

    cmp r1, r2
    bge End

    @ Calculate the offset of arr[i]
    mov r0, #4
    mul r1, r0, r1

    @ Get the value of arr[i]
    movw r3, #:lower16:arr
    movt r3, #:upper16:arr
    ldr r4, [r3, r1] @ r4 = arr[i]

    @ sum = sum + arr[i]
    movw r5, #:lower16:sum
    movt r5, #:upper16:sum
    ldr r6, [r5] @ r6 = sum
    add r6, r6, r4

    str r6, [r5]

    @ Increment i
    movw r0, #:lower16:i
    movt r0, #:upper16:i
    ldr r1, [r0]
    add r1, #1
    str r1, [r0]

    b WHILE


End:
    nop

.data
arr:    .word 1, 2, 3, 4, 5
len:    .word 5
i:      .word 0
sum:    .word 0
