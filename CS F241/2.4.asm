
org 100h

MOV BX,3B7AH  ; Storing a 16-bit number in BX
MOV CX,0C142H ; Storing a 16-bit number in CX
SUB BX,CX   ; Subtracting BX from AX and storing result in AX (BX := BX - CX)
HLT

ret




