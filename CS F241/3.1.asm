
org 100h

MOV CL, 09H ; Storing 9 in register CL
MOV AL, 32H ; Storing 50 degree celsius in register AL
IMUL CL     ; Multiplying 9 with temperature in celsius
MOV CL, 05H ; Storing 5 in register CL
IDIV CL     ; Dividing temperature in celsius by 5
ADD AL, 20H ; Adding 32 to get temperature in farenheit
HLT

ret




