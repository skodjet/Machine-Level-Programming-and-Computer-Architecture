    .global main

main:
    @ //a = b + c
    @ //Move the value stored in b to r0
    @ movw r0, #:lower16:b
    @ movt r0, #:upper16:b
    @ ldr r0, [r0]

    @ //Move the value stored in c to r1
    @ movw r1, #:lower16:c
    @ movt r1, #:upper16:c
    @ ldr r1, [r1]

    @ //Add b and c
    @ add r0, r0, r1 //Adds r0 and r1, and stores the result in r0

    @ //Get the address of a
    @ movw r1, #:lower16:a
    @ movt r1, #:upper16:a

    @ //Store the result of the addition to a
    @ str r0, [r1] //NOTE: This is strange. r0 is NOT the destination.
    @              //Takes the value at r0 and stores it at [r1].


    //d = b - e (subtracting different types)
    movw r0, #:lower16:b
    movt r0, #:upper16:b
    ldr r0, [r0]

    movw r1, #:lower16:e
    movt r1, #:upper16:e
    ldrsb r1, [r1]

    sub r0, r0, r1 //r0 = r0 - r1
    //rsb r0, r0, #1 //r0 = 1 - r0 (reverse subtraction).

    movw r1, #:lower16:d
    movt r1, #:upper16:d
    strh r0, [r1] //Store half a byte so you don't screw stuff up :)

end:
    nop //Means no operation

    mul r0, r1, r2 //r0 = r1 * r2
                   //DESTINATION CANT BE SAME AS FIRST SOURCE

.data
    .align 2
a:  .skip 4
b:  .word 0x7fffff00
c:  .word 55
d:  .short -5
e:  .byte 10
    .skip 1 //Same effect as .align 2 (because short + byte + skip 1 = 4 bytes)
f:  .word 0x12345678    
