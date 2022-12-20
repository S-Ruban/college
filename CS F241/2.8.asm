
org 100h

MOV AX,1927H  ; Storing a 16-bit number in AX
MOV BX,1201H  ; Storing a 16-bit number in BX
DIV BX  ; Dividing AX by BX, storing quotient in AX and remainder in DX
HLT

ret




