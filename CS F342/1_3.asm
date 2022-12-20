.data
onein: .asciiz "Enter first number : "
twoin: .asciiz "Enter second number : "
sumout: .asciiz "The sum is = "
diffout: .asciiz "\nThe difference is = "
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
add $t2, $t0, $t1
sub $t3, $t0, $t1
la $a0, sumout
li $v0, 0x4
syscall
move $a0, $t2
li $v0, 0x1
syscall
la $a0, diffout
li $v0, 0x4
syscall
move $a0, $t3
li $v0, 0x1
syscall
li $v0, 0x1
li $v0, 0xa
syscall