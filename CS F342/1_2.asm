.data
myMsg: .asciiz "Hello. Enter a number : "
output: .asciiz "You have entered : "
.text
main:
la $a0, myMsg
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, output
li $v0, 0x4
syscall
move $a0, $t0
li $v0, 0x1
syscall
li $v0, 0xa
syscall