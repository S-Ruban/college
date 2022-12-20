.data
space: .asciiz " "
print: .asciiz "test"
.text
main:
li $s0,0 						#$s0 always points to the root node of binary tree, initially NULL
get_input: 						#infinite loop for getting number to be inserted in tree, 0 terminates the loop
	li $v0,5
	syscall

	beq $v0,$zero,break_of_loop
	move $a0,$v0 					#$a0 = number to be inserted
	move $a1,$s0 					#$a1 = ptr to the root (holds address of root node), initially NULL
	jal insert_in_tree
	move $s0,$v0 					#v0 adress to the root, storing it in $s0
	j get_input


break_of_loop: 					#exit from loop above for entry value as 0


	move $a0,$s0
	jal inorder_traversal			#inorder traversal, $a0 is argument, holds address of the root
	li $v0,10 						#exit from main
	syscall


insert_in_tree:
	bne $a1,$zero,not_base_case		#check for base case if(pointer == NULL), # then dynamically allocate memory for the new node)

	move $t0,$a0 					# for base case, you can avoid stack pointer and use
									# temporary registers for restoring purposes
	li $a0,12 
	li $v0,9
	syscall 

	sw $t0,0($v0)
	sw $zero,4($v0)
	sw $zero,8($v0)


									#In next few lines, do dynamic memory allocation, $a0 = size(in bytes), $v0 = pointer to
									#the new memory, insert the input value into the created structure, and set left and right
									#child pointers as NULL ($zero), restore value of $a0,then return.
	move $a0,$t0

	jr $ra 						   # return only for base case – not for rest



not_base_case:
	#Taking hint from returnNonBase label, store the required values in stack
	#compare number in current node with the number to be inserted, accordingly traverse left or right

	addi $sp,$sp,-12
	sw $ra,0($sp)
	sw $a1,4($sp)
	sw $s0,8($sp)

	lw $t1,0($a1)
	ble $t1,$a0 right

left:
	addi $a1,$a1,4 		#left node pointer at 4($a1) : after this it’s at 0($a1)
	move $s0,$a1
	lw $a1,($a1) 		# now we have the pointer value – may be null
	jal insert_in_tree 	#return value of this function is in $v0, which holds the address of the newly created child (left or right acc. to value of $s0)
	j returnNonBase

right:
	addi $a1,$a1,8		#traverse right, change value of $a1 accordingly
	move $s0,$a1
	lw $a1,($a1)
	jal insert_in_tree
	j returnNonBase

returnNonBase:
	sw $v0,($s0) 		#NOTE – null value is being updated with the address returned
	lw $ra,($sp)
	lw $a1,4($sp)
	lw $s0,8($sp)
	addi $sp,$sp,12
	move $v0,$a1		#NOTE
	jr $ra

inorder_traversal: 			#a0 is argument, holds address of the root initially
	beq $a0,$zero,return_inorder

	addi $sp,$sp,-12
	sw $ra,($sp)
	sw $a0,4($sp)
	sw $s0,8($sp)
	#traverse left, then print the middle element, then traverse right
	 
	move $s0, $a0
	 
	lw $a0, 4($s0)
	jal inorder_traversal
	 
	lw $a0, ($s0)
	li $v0,1
	syscall
	 
	lw $a0, 8($s0)
	jal inorder_traversal
	 
	 #restore the register values
	 lw $a0,4($sp)
	 lw $ra,($sp)
	 lw $s0,8($sp)
	addi $sp,$sp,12
 
return_inorder:
 
	jr $ra


