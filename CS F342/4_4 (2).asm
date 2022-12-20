.data
float1: .asciiz "Enter first float: "
float2: .asciiz "Enter second float: "
newLine: .asciiz "\n"
equal: .asciiz "both numbers are equal"
minimum: .asciiz "The minimum no. is : "
maximum: .asciiz "\nThe maximum no. is : "
.text
main:
la $a0, float1
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f3, $f0
la $a0, float2
li $v0, 0x4
syscall
li $v0, 0x6
syscall
c.lt.s $f0, $f3
bc1t lesser
c.lt.s $f3, $f0
bc1t greater
la $a0, equal
j Fin
greater:
    mov.s $f5, $f3
    mov.s $f3, $f0
    mov.s $f0, $f5
lesser:
    la $a0, minimum
    li $v0, 0x4
    syscall
    mov.s $f12, $f0
    li $v0, 0x2
    syscall
    la $a0, maximum
    li $v0, 0x4
    syscall
    mov.s $f12, $f3
    li $v0, 0x2
    syscall
    j Fin
Fin:
    li $v0, 0xa
    syscall