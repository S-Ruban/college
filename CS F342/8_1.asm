.data
input_N: .asciiz "Enter the number of elements to input : "
input_arr: .asciiz "Enter the elements : \n"
sum: .asciiz "The sum of elements is : "
.text
main:
la $a0, input_N
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, input_arr
li $v0, 0x4
syscall
move $a0, $t0
sll $a0, $a0, 0x2
move $t3, $a0
li $v0, 0x9
syscall
move $a1, $v0
move $t0, $v0
add $a1, $a1, $a0
loop1:
    li $v0, 0x5
    syscall
    sw $v0, ($t0)
    addi $t0, $t0, 0x4
    blt $t0, $a1, loop1
srl $a0, $a0, 0x2
subu $t0, $t0, 0x4
xor $t1, $t1, $t1
loop2:
    lw $t2, ($t0)
    add $t1, $t1, $t2
    addi $t0, $t0, -4
    addi $t3, $t3, -4
    bgt $t3, $0, loop2
la $a0, sum
li $v0, 0x4
syscall
move $a0, $t1
li $v0, 0x1
syscall
li $v0, 0xa
syscall