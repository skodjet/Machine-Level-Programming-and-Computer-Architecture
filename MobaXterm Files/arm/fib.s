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
    //Call fib(n)
    movw r1, #:lower16:n
    movt r1, #:upper16:n
    ldr r1, [r1] @ r1 = n
    push {r1}
    bl fib
    add sp, #4

    @ ans = fib(n)
    movw r0, #:lower16:ans
    movt r0, #:upper16:ans
    str r3, [r0] @ r0 = ans

    b End



fib:
    @ a: [fp, #8]
    @ x: [fp, #-4]
    @ y: [fp, #-8]
    @ return in r3

    push {lr}
    push {fp}
    mov fp, sp

    ldr r1, [fp, #8] @ r1 = a
    cmp r1, #0
    beq IF
    cmp r1, #1
    bne FALSE
    
    b IF


IF:
    @ return 1
    mov r3, #1
    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr @ return in r3

FALSE:
    @ call fib(a - 1)
    ldr r1, [fp, #8]
    sub r1, r1, #1 @ r1 = a - 1
    push {r1}
    bl fib
    add sp, #4 @ r3 = fib(a - 1)
    sub sp, #4 @ Make space for x
    str r3, [fp, #-4]

    @ call fib(a - 2)
    ldr r1, [fp, #8]
    sub r1, r1, #2 @ r1 = a - 2
    push {r1}
    bl fib
    add sp, #4 @ r3 = fib(a - 2)
    sub sp, #4 @ Make space for y
    str r3, [fp, #-8]
    
    @ return x + y
    ldr r7, [fp, #-4] @ r7 = x
    ldr r8, [fp, #-8] @ r8 = y
    add r3, r7, r8

    mov sp, fp
    pop {fp}
    pop {lr}
    bx lr @ return in r3



End:
    nop



.data
n:      .word 10
ans:    .skip 4
