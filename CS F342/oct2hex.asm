.data
input: .asciiz "Enter an octal number : "
oct: .space 0xc
output: .asciiz "The hexadecimal equivalent is : 0x"
hex: .asciiz "0123456789abcdef"
.text
main:
la $a0, input
li $v0, 0x4
syscall
li $v0, 0x8
la $a0, oct
li $a1, 0xc
syscall
la $a0, oct
xor $t0, $t0, $t0
li $t3, 0xffffffcf
lb $t2, ($a0)
loop1:
    and $t2, $t2, $t3
    sll $t0, $t0, 0x3
    add $t0, $t0, $t2
    addi $a0, $a0, 0x1
    lb $t2, ($a0)
    bne $t2, 0xa, loop1
li $t3, 0xf0000000
la $a0, output
li $v0, 0x4
syscall
# li $t4, 0x1b
# loop2:
#     and $t2, $t2, $t3
#     srlv $t2, $t2, $t4
#     la $a0, hex
#     srl $t3, $t3, 0x4
#     bnez $t3, loop2
li $v0, 0xa
syscall