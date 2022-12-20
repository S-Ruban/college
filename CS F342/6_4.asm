    .text
    .globl main
main:
    addi $a0, $0, 4
    jal fact
    nop

    move $a0, $v0
    li $v0, 1
    syscall

    li $v0, 10
    syscall

fact:
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)

    slti $t0, $a0, 1
    beq $t0, $0, L1
    nop

    addi $v0, $0, 1
    addi $sp, $sp, 8
    jr $ra

L1:
    addi $a0, $a0, -1
    jal fact
    nop

    lw $a0, 0($sp)
    lw $ra, 4($sp)
    addi $sp, $sp, 8

    mul $v0, $a0, $v0

    jr $ra