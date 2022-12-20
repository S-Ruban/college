.text
.globl main
main:
    addi $s0, $0, 9
    add $a0, $s0, 0

    jal add10

    add $s1, $v0, 0
    add $s0, $s1, 0

    li $v0, 10
    syscall

add10:
    addi $sp, $sp, -4
    sw $s0, 0($sp)


    addi $s0, $a0, 10
    add $v0, $s0, $0

    lw $s0, 0($sp)
    addi $sp, $sp, 4

    jr $ra