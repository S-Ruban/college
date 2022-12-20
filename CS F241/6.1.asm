
org 100h

MOV SI,0500h    ; Moves SI to location where size of array is stored
MOV CL,[SI]     ; CL contains size of array (outer loop)
DEC CL          ; Decrease CL by 1

L1:             ; L1 is the outer loop of bubble sort
MOV SI,0500h    ; Moves SI to location where size of array is stored
MOV CH,[SI]     ; Move size of array to CH (for inner loop)
DEC CH          ; Reduce CH
INC SI          ; Move to first element of array
L2:             ; L2 is the inner loop of buble sort
MOV AL,[SI]     ; Move one value to AL
INC SI          ; Moves SI to next value in array
CMP AL,[SI]     ; Compares current value and previous value
JC L3           ; Jumps to L3 if there is no need to swap, else next statement gets executed to swap
XCHG AL,[SI]    ; Swap current element with AL
DEC SI          ; Move pointer to previous element
XCHG AL,[SI]    ; Swap previous element with AL
INC SI          ; Move pointer back to current element
L3:             ; L3 manages L1 and L2, depening on loop counters CH and CL
DEC CH          ; Reduce inner loop by 1 (nexy iteration of inner loop)
JNZ L2          ; Goes back to L2 as long as CH > 0
DEC CL          ; Reduce outer loop by 1 (next iteration of outer loop)
JNZ L1          ; Goes back to L1 as long as CL > 0

HLT

ret




