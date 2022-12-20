.data
input_x: .asciiz "Enter x : "
input_y: .asciiz "Enter y : "
pow_sym: .asciiz " ^ "
equal: .asciiz " = "
newline: .asciiz "\n"
.text
main:
la $a0, input_x
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, input_y
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t1, $v0
jal pow
add $t0, $t0, $t1
sub $t1, $t0, $t1
sub $t0, $t0, $t1
jal pow
li $v0, 0xa
syscall

pow:
    li $t2, 0x1
    xor $t3, $t3, $t3
    loop:
        mul $t2, $t2, $t0
        addi $t3, $t3, 1
        blt $t3, $t1, loop
    move $a0, $t0
    li $v0, 0x1
    syscall
    la $a0, pow_sym
    li $v0, 0x4
    syscall
    move $a0, $t1
    li $v0, 0x1
    syscall
    la $a0, equal
    li $v0, 0x4
    syscall
    move $a0, $t2
    li $v0, 0x1
    syscall
    la $a0, newline
    li $v0, 0x4
    syscall
    jr $ra