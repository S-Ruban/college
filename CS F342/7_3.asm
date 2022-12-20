.ktext 0x80000180
#The exception handler cannot store the old values from $at,$a0,$a1) registers on the stack, as would an
#ordinary routine, because the cause of the exception might have been a memory reference that used a
#bad value (such as 0) in the stack pointer.
move $k1, $at # Save $at register. $k1,$k2 are exception handler register
sw $a0, save0 # Handler is not re-entrant(i.e interrupts are disabled) and can’t use
sw $a1, save1 # stack to save $a0, $a1
# Don’t need to save $k0/$k1

#the exception handler uses the value from the Cause register to test if the exception was caused by an
#interrupt (see the preceding table). If so, the exception is ignored. If the exception was not an interrupt, #the
#handler calls print_excp to print a message.

mfc0 $k0, $13 # movee Cause into $k0, $13 is CAUSE register
srl $a0, $k0, 2 # Extract ExcCode field(bits 2-6 in cause register)
andi $a0, $a0, 0xf
bgtz $a0, done # Branch if ExcCode is int (0)
move $a0, $k0 # movee Cause into $a0
mfc0 $a1, $14 # movee EPC into $a1
jal print_excp # Print exception error message
done: mfc0 $k0, $14 # Bump EPC
addiu $k0, $k0, 4 # Do not re-execute faulting instruction
mtc0 $k0, $14 # EPC
mtc0 $0, $13 # Clear Cause register
mfc0 $k0, $12 # Fix Status register
andi $k0, 0xfffd # Clear EXL bit which allows subsequent exceptions to change the EPC register
ori $k0, 0x1 # Enable interrupts
mtc0 $k0, $12
lw $a0, save0
lw $a1, save1
move $at, $k1
eret
.kdata
save0: .word 0
save1: .word 0