    .global main

main:
    //Using immediate. Moving small values into the register
    //mov r0, #123 //Second operand can be immediate or direct
    //mov r1, #0xaaaa //Hexadecimal. Can also do octal if you wanted to. 
   // mov r2, #('A') //Character literal. ASCII code used

   //Moving bigger values
   //mov r0, #0x12345678 //Remember each ARM instruciton is 32 bits
                        //It doesn't have room to hold this 32 bit number.
                        //mov can only handle up to 16 bits.


    mov r0, #0x5678 
    movt r0, #0x1234 //Moves the upper half. Doesn't wipe out value.

    //Let's try to move the decimal number 1 million
    //mov r0, #1000000
    movw r0, #:lower16: 1000000 //movw does the same thing as mov.
                                //#:lower16: means just take the lower 16 bits.
    movt r0, #:upper16: 1000000

    mov r1, r0



