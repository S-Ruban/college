.data
input_name: .asciiz "Enter student's name : "
input_roll: .asciiz "Enter student's roll no : "
input_cgpa: .asciiz "Enter student's CGPA : "
name: .space 0x14
output_name: .asciiz "\nStudent's name : "
output_roll: .asciiz "Student's roll no : "
output_cgpa: .asciiz "\nStudent's CGPA : "
.text
main:
li $t1, 0x14
la $a0, input_name
li $v0, 0x4
syscall
la $a0, name
li $a1, 0x14
li $v0, 0x8
syscall
la $a0, input_roll
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, input_cgpa
li $v0, 0x4
syscall
li $v0, 0x6
syscall
li $a0, 0x1c
li $v0, 0x9
syscall
move $a1, $v0
xor $t2, $t2, $t2
la $a0, name
copy:
    lb $t3, ($a0)
    sb $t3, ($v0)
    addi $v0, $v0, 0x1
    addi $a0, $a0, 0x1
    addi $t2, $t2, 0x1
    blt $t2, $t1, copy
sw $t0, 0x14($a1)
s.s $f0, 0x18($a1)
la $a0, output_name
li $v0, 0x4
syscall
move $a0, $a1
syscall
la $a0, output_roll
li $v0, 0x4
syscall
lw $a0, 0x14($a1)
li $v0, 0x1
syscall
la $a0, output_cgpa
li $v0, 0x4
syscall
l.s $f12, 0x18($a1)
li $v0, 0x2
syscall
li $v0, 0xa
syscall