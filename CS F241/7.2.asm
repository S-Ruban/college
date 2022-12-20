
org 100h

MOV SI,3000H    ; 0700:3000 contains the original string
MOV DI,2004H    ; 0700:2000 will contain the reversed string
MOV CX,0005H    ; CX contains the length of the string
L1: CLD         
    LODSB       ; SI := SI + 1
    STD         
    STOSB       ; DI := DI - 1
    LOOP L1
HLT

ret




