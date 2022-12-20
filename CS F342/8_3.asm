.data
input: .asciiz "Enter a number to insert into binary tree (0 to stop):\n"
root: .word 0x0 0x0 0x0
.text
main:
la $a0, input
li $v0, 0x4
syscall
xor $t2, $t2, $t2
input_loop:
    li $v0, 0x5
    syscall
    beq $v0, $0, out1
    addi $t2, $t2, 0x1
    la $a0, root
    insert:
        lw $t0, ($a0)
        bgez $t0, out2
        ble $v0, $t0, move_left
        bgt $v0, $t0, move_right
        move_left:
            lw $a0, 0x4($a0)
            j insert
        move_right:
            lw $a0, 0x8($a0)
            j insert
        out2:
            move $t1, $v0
            li $a0, 0xb
            li $v0, 0x9
            syscall
            sw $t1, ($v0)
    j input_loop
out1:
sll $a0, $t2, 0x2
li $v0, 0x9
syscall
xor $t2, $t2, $t2
move $a0, $v0
la $t3, root
loop1:
    sw $t3, ($a0)
    addi $a0, $a0, 0x4
    addi $t2, $t2, 0x1
    lw $t3, 0x4($t3)
    bge $t3, $0, loop1
    blt $t2, $0, out3
    move $t4, $a0
    subu $t4, $t4, 0x4
    subu $t2, $t2, 0x1
    lw $a0, ($t4)
    li $v0, 0x1
    syscall
    addi $t4, $t4, 0x4
    addi $t2, $t2, 0x1
    lw $t3, 0x8($t4)
    subu $t4, $t4, 0x4
    subu $t2, $t2, 0x1
    j loop1
out3:
li $v0, 0xa
syscall