.data
val1: .float 0.001
newline: .asciiz "\n"
.text
main:
l.s $f12, val1
li $v0, 0x2
syscall
la $a0, newline
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f12, $f0
li $v0, 0x2
syscall
li $v0, 0xa
syscall