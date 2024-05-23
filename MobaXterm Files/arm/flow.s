    .global main

main:

    //If statement
    //Get the value of x
    movw r0, #:lower16:x
    movt r0, #:upper16:x
    ldr r1, [r0]

    cmp r1, #10 //r1 - 10 is what to 0?
    bge L1 //Go to L1 if the result of the cmp is greater than or equal to 0.
    add r1, #1
    str r1, [r0]


L1: //x = 20
    mov r1, #20
    str r1, [r0]



.data
x:  .word 5
