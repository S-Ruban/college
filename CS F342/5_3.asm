.data
str: .space 0x6
revstr: .space 0x6
input: .asciiz "Enter a string : "
rev: .asciiz "The reverse of "
is: .asciiz " is "
newline: .asciiz "\n"
.text
main:
la $a0, input
li $v0, 0x4
syscall
la $a0, str
li $a1, 0x6
li $t0, 0x4
li $v0, 0x8
syscall
la $a0, newline
li $v0, 0x4
syscall
la $t1, str
add $t1, $t1, $t0
la $t2, revstr
loop:
    lb $t4, ($t1)
    sb $t4, ($t2)
    addi $t1, $t1, -1
    addi $t2, $t2, 1
    addi $t0, $t0, -1
    bgez $t0, loop
    j out
out:
la $a0, rev
li $v0, 0x4
syscall
la $a0, str
li $v0, 0x4
syscall
la $a0, is
li $v0, 0x4
syscall
la $a0, revstr
li $v0, 0x4
syscall
li $v0, 0xa
syscall