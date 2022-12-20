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
li $v0, 0x6
syscall
mov.s $f1, $f0
la $a0, twoin
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f2, $f0
add.s $f3, $f1, $f2
sub.s $f4, $f1, $f2
# neg.s $f2, $f2
# add.s $f4, $f1, $f2
la $a0, sumout
li $v0, 0x4
syscall
mov.s $f12, $f3
li $v0, 0x2
syscall
la $a0, diffout
li $v0, 0x4
syscall
mov.s $f12, $f4
li $v0, 0x2
syscall
li $v0, 0xa
syscall