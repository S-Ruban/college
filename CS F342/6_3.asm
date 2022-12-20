.data
in1: .asciiz "Enter 1 for triangle, 2 for square : "
in2: .asciiz "Enter number of stars : "
star: .asciiz "*"
newline: .asciiz "\n"
.text
main:
la $a0, in1
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $s0, $v0
la $a0, in2
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $s1, $v0
beq $s0, 0x1, rectangle
beq $s0, 0x2, triangle
li $v0, 0xa
syscall

rectangle:
    xor $t1, $t1, $t1
    move $s2, $s1
    loop1:
        jal print_star_line
        addi $t1, $t1, 1
        ble $t1, $s1, loop1
    jr $ra

triangle:
    li $t1, 0x1
    loop2:
        move $s2, $t1
        jal print_star_line
        addi $t1, $t1, 1
        ble $t1, $s1, loop2
    jr $ra

print_star_line:
    xor $t0, $t0, $t0
    li $v0, 0x4
    loop:
        la $a0, star
        syscall
        addi $t0, $t0, 1
        blt $t0, $s2, loop
        la $a0, newline
        syscall
        jr $ra