
org 100h

MOV AX,0EF1AH ; Storing a 16-bit number in AX
MOV BX,0CD50H ; Storing a 16-bit number in BX
MUL BX        ; Multiplying BX with AX and storing result in DX and AX
HLT

ret




