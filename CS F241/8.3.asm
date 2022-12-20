
org 100h
.data
msg db 'BITS-PILANI$'

.code
MOV AX,@data
MOV DS,AX
MOV DX,offset msg
MOV AH,09H
INT 21H

ret




