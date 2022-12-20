.data
input: .asciiz "Enter n : "
output: .asciiz "The sum of first n natural numbers = "
.text
main:
li $t1, 0x1
# li $t2, 0x2
la $a0, input
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, output
li $v0, 0x4
syscall
# mul $a0, $t0, $t0
# add $a0, $a0, $t0
# div $a0, $a0, $t2
xor $a0, $a0, $a0
loop:
    add $a0, $a0, $t0
    sub $t0, $t0, $t1
    bgt $t0, $0, loop
li $v0, 0x1
syscall
li $v0, 0xa
syscall