
org 100h

MOV CL,7AH  ; Storing an 8-bit number in CL
MOV DL,4CH  ; Storing an 8-bit number in DL
SUB CL,DL   ; Subtracting DL from CL and storing result in CL (CL := CL - DL)
HLT         ; Stopping execution of the program

ret




