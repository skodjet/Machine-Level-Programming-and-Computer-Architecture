    .global main

main:
    movw r1, #:lower16:sum
    movt r1, #:upper16:sum
    mov r2, #10
    strh r2, [r1]



.data
sum:    .skip 2