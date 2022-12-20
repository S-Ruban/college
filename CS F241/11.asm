
org 100h

#start=led_display.exe#

#make_bin#

name "led" 

mov ax,1234
out 199,ax

mov ax, -5678
out 199, ax

mov ax, 0h  ; can also do xor ax,ax
x1:
  out 199, ax  
  inc ax
jmp x1

hlt


ret




