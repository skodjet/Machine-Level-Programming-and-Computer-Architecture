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
    @ i = 0
    movw r1, #:lower16:i
    movt r1, #:upper16:i
    mov r2, #0
    strb r2, [r1]

    ldrsb r2, [r1] @ r2 = i

    movw r1, #:lower16:n
    movt r1, #:upper16:n
    ldr r5, [r1] @ r5 = n




FOR:
    cmp r2, r5
    bge End

    @sum += i * i * i
    mul r0, r2, r2
    mul r0, r2, r0 @r0 = i * i * i

    add r3, r3, r0
    movw r7, #:lower16:sum
    movt r7, #:upper16:sum
    strh r3, [r7]

    @i++
    add r2, #1
    movw r1, #:lower16:i
    movt r1, #:upper16:i
    strb r2, [r1]

    b FOR


End: 
    nop


.data
n:      .word 10
i:      .byte 5
.skip 1
sum:    .skip 2

