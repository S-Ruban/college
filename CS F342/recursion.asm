.data 
	str: .asciiz "Fact: "
.text
	main:
		li $a0,8				# load x
		li $a1,1				# load i
		jal fact				# fact(x)
		#v0 has value now
		move $a0,$v0
		jal print_str
		li $v0,10
		syscall

	fact:
		addi $sp,$sp,-12		# reduce sp to accomodate 12/4 = 3 integers
		sw  $a0,($sp)			# [sp] = x
		sw $a1,4($sp)			# [sp+4] = i
		sw $ra,8($sp) 			# [sp+8] = ra
		
		beq $a0,0,end
		mul $a1,$a0,$a1			# i := x*i
		addi $a0,$a0,-1			# x--
		jal fact				# fact(x)
		j ret
	end:
		move $v0, $a1			# v0 := fact(x), final answer
	ret:						# restore values
		lw $ra, 8($sp)			
		lw $a1, 4($sp)
		lw $a0,($sp)
		add $sp,$sp,12			# restore stack
		jr $ra					# resume instrution flow

	print_str:
		addi $sp,$sp,-4			# reduce sp to accomodate 4/4 = 1 integer
		sw $a0,($sp)			# [sp] = $a0 (value to be printed)
		la $a0, str
		li $v0,4 
		syscall
		lw $a0,($sp)			# retrieve integer to print
		li $v0,1
		syscall
		jr $ra