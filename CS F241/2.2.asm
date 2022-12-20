
org 100h

MOV AX,1A4CH  ; Storing a 16-bit number in AX
MOV BX,0B1DEH ; Storing a 16-bit number in BX
ADD AX,BX   ; Addding BX to AX and storing result in AX (AX := AX + BX)
HLT         ; Stopping execution of the program

ret




