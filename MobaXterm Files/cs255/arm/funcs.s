    .global main

main:

    movw r0, #:lower16:x
    movt r0, #:upper16:x
    mov r1, #1
    str r1, [r0]
    bl func

    bl func
    mov r1, #20
    str r1, [r0]
    b End


func:
    movw r0, #:lower16:x
    movt r0, #:upper16:x
    ldr r1, [r0]
    add r1, #1
    str r1, [r0]


    push {lr}
    bl other
    pop {lr}
    bx lr


other:
    movw r0, #:lower16:y
    movt r0, #:upper16:y
    ldr r1, [r0] @r1 = y
    sub r1, #1
    str r1, [r0]
    bx lr

End:
    nop

    .data
x:  .skip 4
y:  .word 10
