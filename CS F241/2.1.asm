
org 100h

MOV CL,12H  ; Storing an 8-bit number in CL
MOV DL,0CAH ; Storing an 8-bit number in DL
ADD CL,DL   ; Addding DL to CL and storing result in CL (CL := CL + DL)
HLT         ; Stopping execution of the program 

ret




