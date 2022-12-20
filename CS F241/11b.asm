#start=led_display.exe#
#make_bin#

name "led"

mov ax,0x00
out 0xc7, ax
mov ax,0xfffb
mov bx,0x0006
disp: out 0xc7,ax
      inc ax
      cmp ax,bx
      jl disp

hlt

ret