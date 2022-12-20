.data
str1:    .asciiz "Give 2 nonnegative integers, 1 per line: \n"
str2:    .asciiz "The gcd of "
str3:    .asciiz " and "
str4:    .asciiz " is: "
str5:    .asciiz "\n"        

        .text
main:   addi $sp, $sp, -4     	# create a stack frame 
        sw   $ra, 0($sp)      	# save the return address

again:  la   $a0, str1        	# a pseudo assembly instruction
        li   $v0, 4           	# print of str1; also pseudo
        syscall               	#
    
        li   $v0, 5           	# get the first number
        syscall               	# and put it in $v0
        move $s0, $v0         	# $s0=$v0
        bltz $s0, again      	# if $s0<=0 go to again 
        move $a0, $s0      # $a0=$s0
        move $a1, $s1      # $a1=$s1
        jal  gcd           # go to gcd
        move $t0, $v0      # $t0=$v0

        la   $a0, str5     #
        li   $v0, 4        # print of str5
        syscall            #
            
        lw   $ra, 0($sp)   # restore the return address 
        addi $sp, $sp, 4   # eliminate the stack frame
        jr   $ra           # return to caller

        # li $v0, 10
        # syscall

gcd :   addi $sp, $sp, -4   # create 4-word-long stack frame
        sw   $ra, 0($sp)    # save the return address
        beqz $a1, exit_gcd  # if $a1=0 go to exit_gcd 
        div  $a0, $a1       # Lo=$a0/$a1 ;Hi=$a0 mod $a1
        mfhi $t1            # $t1=Hi
        move $a0,$a1        # $a0=$a1 (pseudo assembly instr.)       
        move $a1,$t1        # $a1=$t1
        jal  gcd            # recursive call to gcd

exit_gcd:  
         move $v0, $a0       # $v0=$a0
         lw   $ra, 0($sp)    # restore the return address 
         addi $sp, $sp, 4    # adjust stack pointer
         jr   $ra            # return to caller

