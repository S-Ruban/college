
org 100h

MOV AL,1DH  ; Storing an 8-bit number in AL
MOV BL,77H  ; Storing an 8-bit number in BL
MUL BL   ; Multiplying BL with AL and storing result in AX (AX := AL * BL)
HLT         ; Stopping execution of the program

ret




