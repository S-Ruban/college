.data
str0: .asciiz "\nMul: "
str1: .asciiz "\nDiv: "
str2: .asciiz "\nRemainder: "
.text
main:
li $t0, 0x12c # 300
li $t1, 0x47 # 71
la $a0, str0
li $v0, 0x4
syscall
mul $a0, $t0, $t1
li $v0, 0x1 # print from $a0 syscall
syscall
la $a0, str1
li $v0, 0x4
syscall
div $a0, $t0, $t1
move $t2, $a0
li $v0, 0x1 
syscall # print from $a0 syscall
# Modify to also print the modulo / remainder
la $a0, str2
li $v0, 0x4
syscall
mul $t3, $t2, $t1
sub $a0, $t0, $t3
li $v0, 0x1
syscall
li $v0, 0xa
syscall