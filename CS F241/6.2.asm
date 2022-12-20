
org 100h

MOV BX,1300H
MOV BP,1400H
MOV DI,1500H
MOV SI,0000H    ; Offset pointing to first element of first matrix
MOV CL,09H      ; Since it is a 3x3 matrix
L1: MOV AL,[BX+SI]  ; Move element from first matrix into AL
    ADD AL,[BP+SI]  ; Add element from first matrix to element of second matrix
    MOV [DI],AL     ; Move sum of elements into memory
    INC SI          ; Move to next element in first matrix
    INC DI          ; Move to next element in second matrix
    LOOP L1         ; Repeat loop as long as CL > 0
    HLT

ret




