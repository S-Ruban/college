.data
input: .asciiz "Enter a number : "
yes: .asciiz " is even."
no: .ascii " is odd."
.text
main:
la $a0, input
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t2, $v0
li $t1, 0x1
move $a0, $v0
li $v0, 0x1
syscall
and $t0, $t2, $t1
beq $t0, $0, ye
la $a0, no
li $v0, 0x4
syscall
b Fin
ye:
    la $a0, yes
    li $v0, 0x4
    syscall
Fin:
    li $v0, 0xa
    syscall