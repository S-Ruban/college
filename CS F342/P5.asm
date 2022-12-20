.data
single_input: .asciiz "Input for Single Precision\n"
double_input: .asciiz "\nInput for Double Precision\n"
a_1: .asciiz "Enter a_1: "
a_2: .asciiz "Enter a_2: "
a_3: .asciiz "Enter a_3: "
b_1: .asciiz "Enter b_1: "
b_2: .asciiz "Enter b_2: "
b_3: .asciiz "Enter b_3: "
x: .asciiz "Enter x: "
single_output: .asciiz "Output (single precision): "
double_output: .asciiz ", Output (double precision): "
difference: .asciiz ", Diff: "
.text
main:
la $a0, single_input
li $v0, 0x4
syscall
la $a0, a_1
syscall
li $v0, 0x6
syscall
mov.s $f1, $f0
la $a0, a_2
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f3, $f0
la $a0, a_3
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f5, $f0
la $a0, b_1
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f7, $f0
la $a0, b_2
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f9, $f0
la $a0, b_3
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f11, $f0
la $a0, x
li $v0, 0x4
syscall
li $v0, 0x6
syscall
mov.s $f15, $f0
mul.s $f29, $f15, $f15  # num = x*x
mul.s $f29, $f29, $f1   # num = a1*x*x
mul.s $f17, $f15, $f3   # f17 = b1*x
add.s $f29, $f29, $f17  # num = a1*x*x+b1*x
add.s $f29, $f29, $f5   # num = a1*x*x+b1*x+c1
mul.s $f19, $f15, $f15  # num = x*x
mul.s $f19, $f19, $f7   # num = a2*x*x
mul.s $f17, $f15, $f9   # f17 = b2*x
add.s $f19, $f19, $f17  # num = a2*x*x+b2*x
add.s $f19, $f19, $f11  # num = a2*x*x+b2*x+c2
div.s $f29, $f29, $f19  # num = (a1*x*x+b1*x+c1)/(a2*x*x+b2*x+c2)
la $a0, double_input
li $v0, 0x4
syscall
la $a0, a_1
syscall
li $v0, 0x7
syscall
mov.d $f2, $f0
la $a0, a_2
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f4, $f0
la $a0, a_3
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f6, $f0
la $a0, b_1
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f8, $f0
la $a0, b_2
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f10, $f0
la $a0, b_3
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f12, $f0
la $a0, x
li $v0, 0x4
syscall
li $v0, 0x7
syscall
mov.d $f14, $f0
mul.d $f30, $f14, $f14  # num = x*x
mul.d $f30, $f30, $f2   # num = a1*x*x
mul.d $f16, $f14, $f4   # f16 = b1*x
add.d $f30, $f30, $f16  # num = a1*x*x+b1*x
add.d $f30, $f30, $f6   # num = a1*x*x+b1*x+c1
mul.d $f18, $f14, $f14  # num = x*x
mul.d $f18, $f18, $f8   # num = a2*x*x
mul.d $f16, $f14, $f10  # f16 = b2*x
add.d $f18, $f18, $f16  # num = a2*x*x+b2*x
add.d $f18, $f18, $f12  # num = a2*x*x+b2*x+c2
div.d $f30, $f30, $f18  # num = (a1*x*x+b1*x+c1)/(a2*x*x+b2*x+c2)
la $a0, single_output
li $v0, 0x4
syscall
mov.s $f12, $f29
li $v0, 0x2
syscall
la $a0, double_output
li $v0, 0x4
syscall
mov.d $f12, $f30
li $v0, 0x3
syscall
cvt.d.s $f26, $f29
sub.d $f12, $f12, $f26
la $a0, difference
li $v0, 0x4
syscall
li $v0, 0x3
syscall
li $v0, 0xa
syscall