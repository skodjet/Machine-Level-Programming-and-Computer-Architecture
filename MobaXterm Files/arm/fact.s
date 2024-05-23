    .global main

main:
    mov r5, #4
    push {r5}
    bl fact
    add sp, #4 @r0 = 4!
    movw r1, #:lower16:ans
    movt r1, #:upper16:ans
    str r0, [r1]
    b End


fact:
    @ n: [fp, #8]
    @ temp: [fp, #-4]
    @return  r0
    push {lr}
    push {fp}
    mov fp, sp
    mov r0, #1
    push {r0}

    ldr r0, [fp, #8] @r0 = n
    cmp r0, #0
    beq True

    cmp r0, #1
    bne Else

True:
    ldr r0, [fp, #-4]
    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr

Else:
    sub r0, #1 @ r0 = n - 1
    push {r0}
    bl fact
    add sp, #4 @ r0 = fact(n - 1)
    ldr r1, [fp, #8] @ r1 = n

    mul r2, r0, r1

    str r2, [fp, #-4] @temp = n * fact(n - 1)

    ldr r0, [fp, #-4] @ return temp in r0

    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr


End:
    nop


    .data
ans:    .skip 4
