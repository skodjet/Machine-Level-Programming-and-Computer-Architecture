/*
* THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING

A TUTOR OR CODE WRITTEN BY OTHER STUDENTS - Tommy Skodje
*
*
*/
.global main
.data

a:        .word -4567

.text

main:


/*******************************************************************
*
* Write the assembler instruction to each question after the
* CORRESPONDING LABEL:
*                       Q1, Q2, Q3, ..... Q10
* Define the variable for each question after the
* CORRESPONDING LABEL:
*                       v1, v2, v3, ..... v10
*
* The v1, v2,.. labels are towards the end of the file,
*
* *** Failure to do so will result in point dedections !!! ***
*******************************************************************/

/*******************************************************************
* Put your assembler instructions AFTER this line
*******************************************************************/

/**************************************************************************
* Define an uninitialized byte variable at label v1 (see the end of
* this file) and  write the assembler instruction at label Q1 to
* move the byte value 23 into this variable.
*
* Do NOT forget to SKIP some horizontal space (or use TAB) !!!
**************************************************************************/
Q1:
        //Get the address of v1
        movw r0, #:lower16:v1
        movt r0, #:upper16:v1

        //Store 23 into v1
        ldrsb r1, [r0]
        add r1, #23
        strb r1, [r0]


/**************************************************************************
* Define an initialized byte variable at label v2 with initial value -14
* and write the assembler instructions at label Q2 to move the byte value
* at memory location B into this variable.
*
**************************************************************************/
Q2:
       //Move B into the register
       movw r0, #:lower16:B
       movt r0, #:upper16:B
       ldrsb r0, [r0]

       //Find the address of v2
       movw r1, #:lower16:v2
       movt r1, #:upper16:v2

       //Move the value of B into v2
       strb r0, [r1]


/**************************************************************************
* Define an initialized byte variable at label v3 with initial value -105
* and write the assembler instructions at label Q3 to move the byte value
* of the sum of v1 and v2.
**************************************************************************/
Q3:
        //Move v1 and v2 into registers
        movw r0, #:lower16:v1
        movt r0, #:upper16:v1
        ldrsb r0, [r0]

        movw r1, #:lower16:v2
        movt r1, #:upper16:v2
        ldrsb r1, [r1]

        //Get the address of v3
        movw r2, #:lower16:v3
        movt r2, #:upper16:v3

        //Add the values and store the sum to v3
        add r0, r0, r1
        strb r0, [r2]


/**************************************************************************
* Define an initialized byte variable at label v4 with initial value -12
* and write the assembler instructions at label Q4 to move the byte value
* from this variable to memory location S - you should see -8 moved
**************************************************************************/
Q4:       
        //Get the value of S
        movw r0, #:lower16:S
        movt r0, #:upper16:S
        ldrsh r0, [r0]

        //Get the address of v4
        movw r1, #:lower16:v4
        movt r1, #:upper16:v4

        //Move S's value into v4
        strb r0, [r1]


/**************************************************************************
* Define an uninitialized short variable at label v5 and write
* the assembler instructions at label Q5 to move the short value 5635
* into this variable.
**************************************************************************/
Q5:
        //Get the address of v5
        movw r0, #:lower16:v5
        movt r0, #:upper16:v5

        //Load v5, store 5635 in it, and put it back in data.
        //5635 is too big to add, so it must be moved into a register.
        movw r1, #5635
        strh r1, [r0]


/**************************************************************************
* Define an initialized short variable at label v6 with initial value -53
* and write the assembler instructions at label Q6 to move the short value
* at memory location S into this variable - you should see -4 moved
**************************************************************************/
Q6:
        //Get the value of S
        movw r0, #:lower16:S
        movt r0, #:upper16:S
        ldrsh r0, [r0]

        //Get the address of v6
        movw r1, #:lower16:v6
        movt r1, #:upper16:v6

        //Move the value of S into v6
        strh r0, [r1]


/**************************************************************************
* Define an initialized short variable at label v7 with initial value -1
* and write the assembler instructions at label Q7 to move the sum of
* v5 and v6
**************************************************************************/
Q7:
        //Get the values of v5 and v6
        movw r0, #:lower16:v5
        movt r0, #:upper16:v5
        ldrsh r0, [r0]

        movw r1, #:lower16:v6
        movt r1, #:upper16:v6
        ldrsh r1, [r1]

        //Get the address of v7
        movw r2, #:lower16:v7
        movt r2, #:upper16:v7

        //Add v5 and v6, and sotre the sum in the address of v7
        add r0, r0, r1
        strh r0, [r2]

/**************************************************************************
* Define an uninitialized int variable at label v8 and write the assembler
* instructions at label Q8 to move the int value -200000 into this variable.
**************************************************************************/
Q8:
        //Get the address of v8
        movw r0, #:lower16:v8
        movt r0, #:upper16:v8

        //Get -200000 into a register.
        movw r1, 0xF2C0
        movt r1, 0xFFFC

        //Move -200000 into v8
        str r1, [r0]


/**************************************************************************
* Define an initialized int variable at label v9 with initial value 255
* and write the assembler instructions at label Q9 to move the int value
* at memory location L into this variable.
**************************************************************************/
Q9:
        //Get the address of v9
        movw r0, #:lower16:v9
        movt r0, #:upper16:v9

        //Get the value of L
        movw r1, #:lower16:L
        movt r1, #:upper16:L
        ldr r1, [r1]

        //Move the value of L into v9
        str r1, [r0]


/**************************************************************************
* Define an initialized int variable at label v10 with initial value -224
* and write the assembler instructions at label Q10 to move the sum of
* v8 and v9
**************************************************************************/
Q10:
        //Get the values of v8 and v9
        movw r0, #:lower16:v8
        movt r0, #:upper16:v8
        ldr r0, [r0]

        movw r1, #:lower16:v9
        movt r1, #:upper16:v9
        ldr r1, [r1]

        //Get the address of v10
        movw r2, #:lower16:v10
        movt r2, #:upper16:v10

        //Add v8 and v9
        add r0, r0, r1

        //Store the sum in v10
        str r0, [r2]


Stop:	nop
	nop

/*************************************************
* Write your variable definitions here...
*
* Do NOT forget to SKIP some space (or use TAB) !!!
*************************************************/

.data

v1:     .skip 1


v2:     .byte -14


v3:     .byte -105     


v4:     .byte -12


v5:     .skip 2


v6:     .short -53 


v7:     .short -1 

        .align 2
v8:     .skip 4  


v9:     .word 255


v10:    .word -224   


/*************************************************
* Don't touch the variables below this line
*************************************************/


        .skip  20

B:      .byte   24
        .byte   0
S:      .short  -8
L:      .word   8

.end
