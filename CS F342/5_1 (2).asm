.data
input: .asciiz "Enter a string : "
ispalin: .asciiz "Given string is a palindrome."
isnotpalin: .asciiz "Given string is not a palindrome."
spacebar: .asciiz " "
str: .space 0x65
.text
main:
la $a0, input
li $v0, 0x4
syscall
la $a0, str
li $a1, 0x65
li $v0, 0x8
move $t1, $0
li $t2, 0xa
syscall
la $t0, str
loop:
    lb $a0, ($t0)
    beq $a0, $t2, out
    addi $t0, $t0, 0x1
    addi $t1, $t1, 0x1
    j loop
out:
    la $t0, str
    add $t2, $t0, $t1
    addi $t2, $t2, -1
    loop2:
        lb $t3, ($t0)
        lb $t4, ($t2)
        bne $t3, $t4, no
        addi $t0, $t0, 1
        addi $t2, $t2, -1
        blt $t0, $t2, loop2
        j yes
yes:
    la $a0, ispalin
    li $v0, 0x4
    syscall
    j Fin
no:
    la $a0, isnotpalin
    li $v0, 0x4
    syscall
    j Fin
Fin:
    li $v0, 0xa
    syscall