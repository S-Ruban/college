.data
input: .asciiz "Input : "
output: .asciiz "Output : "
str1: .asciiz "Ruban"
str2: .asciiz "Meshuggah"
newline: .asciiz "\n"
space: .asciiz " "
.text
main:
la $a0, input
li $v0, 0x4
syscall
la $a0, str1
syscall
la $a0, newline
syscall
la $a0, output
syscall
la $s0, str1
jal count_vowel
move $a0, $t0
li $v0, 0x1
syscall
la $a0, newline
li $v0, 0x4
syscall
la $a0, input
li $v0, 0x4
syscall
la $a0, str2
syscall
la $a0, newline
syscall
la $a0, output
syscall
la $s0, str2
jal count_vowel
move $a0, $t0
li $v0, 0x1
syscall
j Fin
count_vowel:
    xor $t0, $t0, $t0
    loop:
        lb $a0, ($s0)
        beq $a0, $0, out
        beq $a0, 0x61, inc
        beq $a0, 0x65, inc
        beq $a0, 0x69, inc
        beq $a0, 0x6f, inc
        beq $a0, 0x75, inc
        beq $a0, 0x41, inc
        beq $a0, 0x45, inc
        beq $a0, 0x49, inc
        beq $a0, 0x4f, inc
        beq $a0, 0x55, inc
        addi $s0, $s0, 1
        j loop
        inc:
            addi $t0, $t0, 1
            addi $s0, $s0, 1
            j loop
    out:
        jr $ra
Fin:
    li $v0, 0xa
    syscall