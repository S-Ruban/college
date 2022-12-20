.data
newline: .asciiz "\n"
.text
main:
li $t0, 0xdba9ac35
move $a0, $t0
li $v0, 0x1
syscall
la $a0, newline
li $v0, 0x4
syscall
srl $v0, $t0, 0x1f
move $a0, $v0
li $v0, 0x1
syscall
la $a0, newline
li $v0, 0x4
syscall
xor $v0, $t0, 0xfffffff
move $a0, $v0
li $v0, 0x1
syscall
li $v0, 0xa
syscall