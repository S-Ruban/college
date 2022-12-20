
org 100h

MOV AX,0000H        ; Setting accumulator register to 0
MOV SI,1100H        ; Move source index to 0700:1100
MOV CX,0004H        ; Update counter CX with N = 4
MOV DX,0000H        ; DX used to keep count of numbers added so far
loop: ADD AL,[SI]   ; Add value at SI to AL
INC SI              ; Move SI to the next number
INC DX              ; Add 1 to DX
CMP CX,DX           ; Check if CX > DX
JNZ loop            ; loop runs as long as CX > DX
DIV CL              ; Dividing AL by CL to give average
MOV [1200H],AX      ; Move the average to 0700:1200
HLT

ret




