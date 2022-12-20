.data
input1: .asciiz "Enter 1st number: "
input2: .asciiz "Enter 2nd number: "
sign1: .asciiz "Sign bit of num1: "
sign2: .asciiz ", Sign bit of num2: "
sign3: .asciiz ", Sign bit of result: "
exp1: .asciiz "\nExponent of num1: "
exp2: .asciiz ", Exponent of num2: "
mantissa1: .asciiz ", Mantissa of num1: "
mantissa2: .asciiz ", Mantissa of num2: "
exp3_nobias: .asciiz "\nExponent without bias of result: "
exp3_bias: .asciiz ", Exponent with bias of result: "
mantissa3_denorm: .asciiz ", Denormalized mantissa after multiplication: "
exp3_norm: .asciiz "\nNormalized Exponent: "
mantissa_norm: .asciiz ", Normalized Mantissa: "
num1: .word 0x0 0x0
num2: .word 0x0 0x0
.text
main:
la $a0, input1
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f1, $f0
la $a0, input2
li $v0, 0x4
syscall
li $v0, 0x6
syscall
la $a0, num1
s.s $f1, ($a0)
lw $t0, ($a0)
la $a0, num2
s.s $f0, ($a0)
lw $t1, ($a0)
la $a0, sign1
li $v0, 0x4
syscall
srl $t2, $t0, 0x1f
move $a0, $t2
li $v0, 0x1
syscall
la $a0, sign2
li $v0, 0x4
syscall
srl $t3, $t1, 0x1f
move $a0, $t3
li $v0, 0x1
syscall
la $a0, sign3
li $v0, 0x4
syscall
xor $a0, $t2, $t3
li $v0, 0x1
syscall
la $a0, exp1
li $v0, 0x4
syscall
srl $t2, $t0, 0x17
subu $a0, $t2, 0x7f
li $v0, 0x1
syscall
move $t6, $a0
la $a0, exp2
li $v0, 0x4
syscall
srl $t3, $t1, 0x17
subu $a0, $t3, 0x7f
li $v0, 0x1
syscall
add $t6, $t6, $a0
li $t4, 0x007fffff
li $t5, 0x00800000
la $a0, mantissa1
li $v0, 0x4
syscall
and $t2, $t0, $t4
or $a0, $t2, $t5
li $v0, 0x1
syscall
move $s0, $a0
la $a0, mantissa2
li $v0, 0x4
syscall
and $t3, $t1, $t4
or $a0, $t3, $t5
li $v0, 0x1
syscall
move $s1, $a0
la $a0, exp3_nobias
li $v0, 0x4
syscall
move $a0, $t6
li $v0, 0x1
syscall
la $a0, exp3_bias
li $v0, 0x4
syscall
addi $a0, $t6, 0x7f
li $v0, 0x1
syscall
move $t6, $a0
la $a0, mantissa3_denorm
li $v0, 0x4
syscall
mult $s0, $s1
mfhi $a0
li $v0, 0x1
syscall
la $a0, exp3_norm
li $v0, 0x4
syscall
move $a0, $t6
li $v0, 0x1
syscall
la $a0, mantissa_norm
li $v0, 0x4
syscall
li $v0, 0xa
syscall