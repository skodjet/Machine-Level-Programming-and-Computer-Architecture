.global main

.text
main:
        @ mov2 r0, #:lower16:x
        @ movt 40, #:upper16:x

        @ ldr r1, [r0]//ldr is load. Get data from 40 and put it in r1
        @             //Default size is 4 bytes

        @ movw r2, #:lower16:y
        @ movt r2, #:upper16:y

        @ ldrsh r2, [r2] //ldrsh means load signed 2 bit data

        @ movw r3, #:lower16:z
        @ movt r3, #:upper16:z

        @ ldrsb r3, [r2]


        @ add r1, r2, r3 //r1 = r2 + r3
        @ add r2, r2, #1 //increments r2 by 1.


        @ strb r3, [r2] //store 1 byte

        //z++
        movw r2, #:lower16:z
        movt r2, #:upper16:z

        ldrsb r3, [r2]

        add r3, #1 //Increments r3 by 1

        strb r3, [r2]




.data

    .align 2 //aligns to 2^2 (4)
w:    .skip 4 //Unitialized 4 bytes
x:    .4byte 1000000
y:    .2byte -4000 //Make sure address is divisible by 2.
z:    .byte 10

    //x, y, and z are labels

    @ .byte 10 // if this is an even address
    @ .align 1
    @ .2byte -4000 //This will have an odd address
    @ .align 2 //2^2 = 4
    @ .byte 1000000
