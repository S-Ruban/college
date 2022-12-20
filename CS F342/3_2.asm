.data
val1: .double 0.001
newline: .asciiz "\n"
.text
main:
l.d $f12, val1
li $v0, 0x3
# l.s $f12, val1
# cvt.d.s $f12, $f12
# li $v0, 0x2
syscall
la $a0, newline
li $v0, 0x4
syscall
li $v0, 0x7
# li $v0, 0x6
syscall
# cvt.s.d $f12, $f0
# li $v0, 0x2
mov.d $f12, $f0
li $v0, 0x3
syscall
li $v0, 0xa
syscall