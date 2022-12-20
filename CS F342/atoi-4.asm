## atoi-4.asm -- reads a line of text, converts it to an integer,
## and prints the integer.
## Handles signed numbers, detects bad characters, and overflow.
## Register usage:
## $t0 - S.
## $t1 - the character pointed to by S.
## $t2 - the current sum.
## $t3 - the "sign" of the sum.
## $t4 - holds the constant 10.
## $t5 - used to test for overflow.
.data ## Start of data declarations:
newline: .asciiz "\n"
overflow_msg: .asciiz "Overflow!\n"
string_space: .space 1024 # reserve 1024 bytes for the string.
.text
main:
la $a0, string_space # read the string S:
li $a1, 1024
li $v0, 8 # load "read_string" code into $v0.
syscall
la $t0, string_space # Initialize S.
li $t2, 0 # Initialize sum = 0.
get_sign:
li $t3, 1 # assume the sign is positive.
lb $t1, ($t0) # grab the "sign"
bne $t1, '-', positive # if not "-", do nothing.
li $t3, -1 # otherwise, set t3 = -1, and
addu $t0, $t0, 1 # skip over the sign.
positive:
li $t4, 10 # store the constant 10 in $t4.
sum_loop:
lb $t1, ($t0) # load the byte at addr S into $t1,
addu $t0, $t0, 1 # and increment S,
## use 10 instead of ’\n’ due to SPIM bug!
beq $t1, 10, end_sum_loop # if $t1 == \n, branch out of loop.
blt $t1, '0', end_sum_loop # make sure 0 <= t1
bgt $t1, '9', end_sum_loop # make sure 9 >= t1
mult $t2, $t4 # multiply $t2 by 10.
mfhi $t5 # check for overflow;
bnez $t5, overflow # if so, then report an overflow.
mflo $t2 # get the result of the multiply
blt $t2, $0, overflow # make sure that it isn’t negative.
sub $t1, $t1, '0' # t1 -= ’0’.
add $t2, $t2, $t1 # t2 += t1.
blt $t2, $0, overflow
b sum_loop # and repeat the loop.
end_sum_loop:
mul $t2, $t2, $t3 # set the sign properly.
move $a0, $t2 # print out the answer (t2).
li $v0, 1
syscall
la $a0, newline # and then print out a newline.
li $v0, 4
syscall
b exit
overflow: # indicate that an overflow occurred.
la $a0, overflow_msg
li $v0, 4
syscall
b exit
exit: # exit the program:
li $v0, 10 # load "exit" into $v0.
syscall # make the system call.
## end of atoi-4.asm