    .global main

main:
    movw r0, #:lower16:a
    movt r0, #:upper16:a
    ldr r1, [r0, #4] //Gets the second element of the array (offset by 4)
    ldr r2, [r0, #(3*4)] //Offset by 12. Get the fourth element of the array.


    .data
a:  .word 1, 2, 3, 4, 5
b:  .skip 80 //Can also do .skip    4*20  
