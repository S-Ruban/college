.data
arr: .space 0x65
input_len: .asciiz "Enter the number of characters : "
input_arr: .asciiz "Enter the characters as a string : "
input_char: .asciiz "Enter the character to search : "
found: .asciiz "The character is present in the array at position "
notfound: .asciiz "The character is not present in the array"
char: .space 0x3
.text
main:
la $a0, input_len
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, input_arr
li $v0, 0x4
syscall
la $a0, arr
li $a1, 0x65
li $v0, 0x8
syscall
la $a0, input_char
li $v0, 0x4
syscall
la $a0, char
li $a1, 0x3
li $v0, 0x8
syscall
la $a0, char
lb $t1, ($a0)
la $a0, arr
xor $t2, $t2, $t2
loop:
    lb $t3, ($a0)
    beq $t1, $t3, yes
    addi $t2, $t2, 1
    addi $a0, $a0, 1
    bge $t2, $t0, no
    j loop
yes:
    la $a0, found
    li $v0, 0x4
    syscall
    move $a0, $t2
    li $v0, 0x1
    syscall
    j Fin
no:
    la $a0, notfound
    li $v0, 0x4
    syscall
    j Fin
Fin:
    li $v0, 0xa
    syscall