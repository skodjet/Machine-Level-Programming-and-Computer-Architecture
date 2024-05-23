    .global main

main:

    //While statement
    //Get the value of x
    movw r0, #:lower16:x
    movt r0, #:upper16:x
    ldr r1, [r0] //r1 = x

WHILE:
    cmp r1, #10 //r1 - 10 is what to 0?
    bgt L1 //Go to L1 if the result of the cmp is greater than 0.

    //x += 2
    add r1, #2
    str r1, [r0]
    b WHILE


L1: //x = 20
    mov r1, #20
    str r1, [r0]



.data
x:  .word 5
