.global main

main:
    movw r0, #:lower16:x
    movt r0, #:upper16:x
    movw r1, #:lower16:y
    movt r1, #:upper16:y

    ldr r2, [r0] //r2 = x
    cmp r2, #10
    bge else    //If condition not true, break to else

    ldr r3, [r1] //r3 = y
    cmp r3, #0
    beq else    //If condition not true, break to else

    add r3, #1
    str r3, [r1]
    b   L1 //Break to L1


else:
    add r2, #1
    str r2, [r0]


L1:
    mov r2, #20
    str r2, [r0]



.data
x:  .word 11
y:  .word 1
z:  .byte 255
