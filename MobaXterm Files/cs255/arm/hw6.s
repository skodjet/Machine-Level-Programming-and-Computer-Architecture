    /*THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING

    A TUTOR OR CODE WRITTEN BY OTHER STUDENTS - Tommy Skodje */
    
    .global main

main:
    mov r0, #70
    mov r1, #20
    push {r0}
    push {r1}

    bl gcd

    @ Clear the stack and store GCD in ans
    add sp, #8

    movw r10, #:lower16:ans
    movt r10, #:upper16:ans
    str r1, [r10]

    b End


gcd:
    @ a: [fp, #12]
    @ b: [fp, #8]
    @ r: [fp, #-4]
    @ return in r1

    push {lr}
    push {fp}
    mov fp, sp

    ldr r1, [fp, #12] @ r1 = a
    ldr r2, [fp, #8] @ r2 = b

    @ if (b == 0) return a
    cmp r2, #0
    bne L1

   mov sp, fp
   pop {fp}
   pop {lr}
   bx lr @ return in r1

L1:
    @call rem(a, b)
    push {r1}
    push {r2}
    bl rem 
    add sp, #8 @ r4 = rem(a, b)
    sub sp, #4 @ Make space for r

    str r4, [fp, #-4] @ r = rem(a, b)

    @call gcd(b, r)
    ldr r1, [fp, #8] @ r1 = b
    ldr r2, [fp, #-4] @ r2 = r
    push {r1}
    push {r2}
    bl gcd
    add sp, #8 @ r1 = gcd(b, r)
    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr



rem:
    @ a: [fp, #12]
    @ b: [fp, #8]
    @ r: [fp, #-8]
    @ q: [fp, #-4]

    push {lr}
    push {fp}
    mov fp, sp

    mov r3, #0  @ r3 = q
    ldr r4, [fp, #12]    @ r4 = r
    push {r3}
    push {r4}

while:
    ldr r5, [fp, #8] @ r5 = b
    cmp r4, r5
    blt L2

    add r3, #1
    str r3, [fp, #-4]
    sub r4, r4, r5
    str r4, [fp, #-8]

    b while

L2:
    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr @return in r4







End:
    nop

.data
ans:    .skip 4
