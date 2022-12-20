.data
    .text
    main:
    li $s0,0 	
    #$s0 root initialized to NULL
    input: #loop terminates when 0 is inserted
        li $v0,5
        syscall
        move $a1, $v0 #a1 stores value of number 
        beq $a1, $zero, exit
        nop
        nop
        jal insert
        nop
        nop
        nop
        move $s0, $v0
        j input
        nop
        nop
    exit :
        move $a0,$s0
        jal inorder_traversal
        nop
        nop
    li $v0,10 #exit from main
    syscall
    insert: 
    bne $s0 , 0, not_empty  #if tree not empty
    nop
    nop
    li $a0, 12 #allocate 3 units
    li $v0, 9
    syscall
    sw $a1, ($v0) # store memory
    sw $zero, 4($v0)
    sw $zero, 8($v0)
    jr $ra #return
    nop
    nop
    not_empty:
    addi $sp,$sp,-8
    sw $s0, ($sp) # store current node address
    sw $ra, 4($sp) # store return address
    lw $t1, ($s0)  
    bgt	$a1, $t1, right# if $a1 > $t1 then target
    nop
    nop
    #left
    left:
    # move $t1, $s0 #t1 : local variable
    # lw $s0, 4($t1)   # s0 now points to left
    lw $s0, 4($s0)
    jal insert       #call insert
    nop
    nop
    lw $s0,($sp)
    sw $v0,4($s0)     #store the returned address as base address
    j left_exit
    nop
    nop
    #right subtree similar to left
    right: 
    # move $t1, $s0
    # lw $s0, 8($t1)
    lw $s0, 8($s0)
    jal insert
    nop
    nop
    lw $s0,($sp)
    sw $v0,8($s0)
    left_exit:
    lw $s0, ($sp)
    move $v0,$s0 #v0 has parent address
    lw $ra,4($sp)#restore ra
    addi $sp, $sp,8
    jr $ra
    nop
    nop
    inorder_traversal:      #a0 is argument, holds address of the root initially
    beq $a0,$zero,return_inorder
    nop
    nop
    addi $sp,$sp,-12
    sw $ra,($sp)
    sw $a0,4($sp)
    sw $s0,8($sp)
    #traverse left, then print the middle element, then traverse right
    move $s0, $a0
    nop
    nop
    lw $a0, 4($s0)#traverse left
    jal inorder_traversal
    nop
    nop 
    lw $a0, ($s0) #print current
    li $v0,1
    syscall
    lw $a0, 8($s0)#traverse right
    jal inorder_traversal
    nop
    nop
    #restore the register values
    lw $ra,($sp)
    lw $a0,4($sp)
    lw $s0,8($sp)
    addi $sp,$sp,12
    return_inorder:
    jr $ra
    nop
    nop