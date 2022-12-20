
org 100h

MOV AX,0000H        ; Initialising accumulator to 0 
MOV SI,0500H        ; Moving source index to 0700:0500
MOV [SI],AL         ; Storing the 1st fibonacci number
INC SI              ; Moving to the next memory location
ADD AL,01H          ; Calculating 2nd fiobnacci number
MOV [SI],AL         ; Storing the 2nd fibonacci number
MOV CX,[0600H]      ; Retrieveing number of fibonacci numbers to calculate
SUB CX,0002H        ; Already calculated first 2 fibonacci numbers
L1: MOV AL,[SI-1]   ; Load the previous fibonacci to accumulator
ADD AL,[SI]         ; Add previous fibonacci number with current fibonacci number
INC SI              ; Move to next memory location
MOV [SI],AL         ; Store the next fibonacci number
LOOP L1             ; Run the loop again as long as CX > 0
HLT

ret




