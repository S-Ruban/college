
org 100h

MOV CX, [0500H] ;
MOV AX, 01H     ; Storing 1 in AX
L1: MUL CX      ; Multiply the AX with the content of address CX points to
LOOP L1         ; Do the loop as long as value that CX points to is not zero
MOV [0600H], AX ; Store lower byte of result in 7000:0600H
MOV [0602H], DX ; Store upper byte of result in 7000:0602H
HLT

ret




