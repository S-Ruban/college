
org 100h

MOV AL,19H  ; Storing an 8-bit number in AL
MOV BL,03H  ; Storing an 8-bit number in BL
DIV BL  ; Dividing AL by BL, storing quotient in AL and remainder in AH
HLT

ret




