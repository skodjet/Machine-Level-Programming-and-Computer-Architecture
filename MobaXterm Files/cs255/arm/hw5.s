.global main

main:
    //Set q = 0 and r = a.
    movw r0, #:lower16:q
    movt r0, #:upper16:q    //r0 = q address
    mov r1, #0
    str r1, [r0]

    movw r1, #:lower16:r
    movt r1, #:upper16:r    //r1 = r address
    movw r2, #:lower16:a
    movt r2, #:upper16:a    //r2 = a address
    ldr r3, [r2]
    str r3, [r1]


while:
    //Compare r to b. If r < b, break.
    ldr r3, [r1]    //r3 = r value
    movw r4, #:lower16:b
    movt r4, #:upper16:b
    ldrsh r4, [r4]  //r4 = b value

    cmp r3, r4
    blt afterawhile

    //q++ and r = r - b
    ldr r5, [r0]    //r5 = q value
    add r5, #1
    str r5, [r0]

    sub r3, r3, r4
    str r3, [r1]

    b while

    
afterawhile:
    //ans = q
    movw r6, #:lower16:ans
    movt r6, #:upper16:ans
    str r5, [r6]

    //Move q to r0 and r to r1
    mov r0, r5
    mov r1, r3


End:
    nop
.data
a:      .word 86
q:      .skip 4
r:      .skip 4
ans:    .skip 2
b:      .short 11
