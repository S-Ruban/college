
org 100h

MOV SI,4000H
MOV DI,4006H
L1: MOV AL,[SI]
    MOV BL,[DI]
    XCHG [SI],BL   
    XCHG [DI],AL
    INC SI
    DEC DI
    CMP DI,SI
    JGE L1          ; Loop if SI < DI
HLT

ret




