.data
newline: .asciiz "\n"
.text
main:
li $a0, 0x20
li $v0, 0x1
syscall
la $a0, newline
li $v0, 0x4
syscall
li $a0, 0x20
jal add10
move $a0, $v0
li $v0, 0x1
syscall
li $v0, 0xa
syscall

add10:
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    addi $v0, $a0, 0xa
    lw $t0, 0($sp)
    addi $sp, $sp, 4
    jr $ra