.data
# Step A start
nums: .word 0x6e91 0xe36b # 28305, 58219
# Step A end
mulsym: .asciiz " * "
eqsym: .asciiz " = "
newline: .asciiz "\n"
minussym: .asciiz " - "
.text
main:
la $t0, nums
lw $s1, ($t0)
lw $s2, 4($t0)
li $v0, 0x1
move $a0, $s1
syscall
la $a0, mulsym
li $v0, 0x4
syscall
li $v0, 0x1
move $a0, $s2
syscall
la $a0, eqsym
li $v0, 0x4
syscall
# Step B start
mul $a0, $s1, $s2
li $v0, 0x1
syscall
# Step B end
la $a0, newline
li $v0, 0x4
syscall
# Step C start
mtc1 $s1, $f1
cvt.s.w $f1, $f1
mtc1 $s2, $f2
cvt.s.w $f2, $f2
mov.s $f12, $f1
li $v0, 0x2
syscall
la $a0, mulsym
li $v0, 0x4
syscall
mov.s $f12, $f2
li $v0, 0x2
syscall
la $a0, eqsym
li $v0, 0x4
syscall
mul.s $f12, $f1, $f2
mov.s $f3, $f12
mov.s $f7, $f3
li $v0, 0x2
syscall
# Step C end
la $a0, newline
li $v0, 0x4
syscall
# Step D start
mtc1 $s1, $f1
cvt.s.w $f1, $f1
mtc1 $s2, $f2
cvt.s.w $f2. $f2
mov.s $f12, $f1
li $v0, 0x2
syscall
la $a0, mulsym
li $v0, 0x4
syscall
mov.s $f12, $f2
li $v0, 0x2
syscall
la $a0, eqsym
li $v0, 0x4
syscall
cvt.w.s $f3, $f3
mfc1 $a0, $f3
li $v0, 1
syscall
# Step D end
la $a0, newline
li $v0, 0x4
syscall
# Step E start
mtc1 $s1, $f2
cvt.d.w $f2, $f2
mtc1 $s2, $f4
cvt.d.w $f4. $f4
mov.d $f12, $f2
li $v0, 0x3
syscall
la $a0, mulsym
li $v0, 0x4
syscall
mov.d $f12, $f4
li $v0, 0x3
syscall
la $a0, eqsym
li $v0, 0x4
syscall
mul.d $f12, $f2, $f4
mov.d $f6, $f12
mov.d $f8, $f6
li $v0, 0x3
syscall
# Step E end
la $a0, newline
li $v0, 0x4
syscall
# Step F start
mtc1 $s1, $f2
cvt.d.w $f2, $f2
mtc1 $s2, $f4
cvt.d.w $f4, $f4
mov.d $f12, $f2
li $v0, 0x3
syscall
la $a0, mulsym
li $v0, 0x4
syscall
mov.d $f12, $f4
li $v0, 0x3
syscall
la $a0, eqsym
li $v0, 0x4
syscall
cvt.w.d $f6, $f6
mfc1 $a0, $f6
li $v0, 1
syscall
# Step F end
la $a0, newline
li $v0, 0x4
syscall
# Step G begin
mov.s $f12, $f7
li $v0, 0x2
syscall
la $a0, minussym
li $v0, 0x4
syscall
mov.d $f12, $f8
li $v0, 0x3
syscall
la $a0, eqsym
li $v0, 0x4
syscall
sub.d $f12, $f8, $f7
li $v0, 0x3
syscall
# Step G end
la $a0, newline
li $v0, 0x4
syscall
li $v0, 0xa
syscall