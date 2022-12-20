.data
myMsg: .asciiz "Hello. Enter a number : "
output: .asciiz "You have entered : "
.text
main:
li $v0, 0x5
syscall
move $a0, $v0
li $v0, 0x1
syscall
li $v0, 0xa
syscall