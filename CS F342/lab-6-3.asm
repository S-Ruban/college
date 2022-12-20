.data
  promptMessage: .asciiz "Enter a number to find its factorial: "
  resultMessage:  .asciiz "\n The factorial of the number is: "
  theNumber:  .word 0
  theAnswer:  .word 0

.text
  .globl main
  main:

  #read numbers
  li $v0, 4
  la $a0, promptMessage
  syscall

  li $v0, 5
  syscall

  sw $v0, theNumber

  # call the factorial function
  lw $a0, theNumber

  jal findFactorial

  sw $v0, theAnswer

  #Dispplay result
  li $v0, 4
  la $a0, resultMessage
  syscall

  lw $v0,1
  lw $a0, theAnswer
  syscall

  # Tell os to end program
  li $v0, 10
  syscall

  #Find findFactorial
  .globl findFactorial
  findFactorial:
      subu $sp, $sp, 8
      sw $ra, 0($sp)
      sw $s0, 4($sp)

      #base case
      li $v0, 1
      beq $a0, 0, factorialDone
      #findfactorial(theNumber-1)
      move $s0, $a0
      sub $a0, $a0, 1
      jal findFactorial

      mul $v0, $s0, $v0

      factorialDone:
        lw $ra, 0($sp) # restoring ra from stack
        lw $s0, 4($sp)
        addu $sp, $sp, 8  # restore the stack

        jr $ra
