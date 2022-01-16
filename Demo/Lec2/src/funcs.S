
.syntax unified

.globl summation
.type summation,%function


summation:
    mov r4, #0

    add_loop:
        subs r1, r1, #1
        ldrb r2, [r0], #1
        ITE EQ
        addeq r4, r4, r2
        subne r4, r4, r2
        bne add_loop
    mov r0, r4
    bx lr
    