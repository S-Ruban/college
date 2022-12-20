.data
input: .asciiz "Enter a decimal number : "
output: .asciiz "The binary equivalent is : "
.text
main:
la $a0, input
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
li $t1, 0x80000000
la $a0, output
li $v0, 0x4
syscall
li $v0, 0x1
li $t2, 0x1f
loop:
    and $a0, $t0, $t1
    srlv $a0, $a0, $t2
    syscall
    subu $t2, $t2, 0x1
    srl $t1, $t1, 0x1
    bnez $t1, loop
li $v0, 0xa
syscall