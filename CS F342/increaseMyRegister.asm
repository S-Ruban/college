.data
  newLine:  .asciiz "\n"
.text
  main:
    addi $s0, $zero, 10

    jal increaseMyRegister

    # Print a newLine
    li $v0,4
    la $a0, newLine
    syscall

    #Print value
    li $v0,1
    move $a0, $s0
    syscall

    #end program
    li $v0, 10
    syscall

increaseMyRegister:
      addi $sp, $sp, -4   # subu $sp, $sp, 4, allocate space 4 bytes in the stack
      sw $s0, 0($sp)


      addi $s0, $s0, 30

      #Print new value in function
      li $v0, 1
      move $a0, $s0   # s0=40
      syscall

      lw $s0, 0($sp)   #s0=10
      addi $sp, $sp, 4

      jr $ra