.data
onein: .asciiz "Enter first number : "
twoin: .asciiz "Enter second number : "
greater: .asciiz " > "
.text
main:
la $a0, onein
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, twoin
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t1, $v0
bgt $t0, $t1, g
move $a0, $t1
li $v0, 0x1
syscall
la $a0, greater
li $v0, 0x4
syscall
move $a0, $t0
li $v0, 0x1
syscall
b Fin
g:
    move $a0, $t0
    li $v0, 0x1
    syscall
    la $a0, greater
    li $v0, 0x4
    syscall
    move $a0, $t1
    li $v0, 0x1
    syscall
    b Fin
Fin:
    li $v0, 10
    syscall