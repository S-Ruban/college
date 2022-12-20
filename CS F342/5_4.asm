.data
input_len: .asciiz "Enter the number of elements in the array : "
input_arr: .asciiz "Enter the elements of the array : \n"
min: .asciiz "The minimum element of the array is : "
max: .asciiz "\nThe maximum element of the array is : "
.text
main:
la $a0, input_len
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t0, $v0
la $a0, input_arr
li $v0, 0x4
syscall
li $v0, 0x5
syscall
move $t2, $v0
move $t3, $v0
li $t1, 0x1
loop:
    li $v0, 0x5
    syscall
    ble $v0, $t2, makemin
    bge $v0, $t3, makemax
    makemin:
        move $t2, $v0
        j done
    makemax:
        move $t3, $v0
        j done
    done:
        addi $t1, $t1, 1
        blt $t1, $t0, loop
        j Fin
Fin:
la $a0, min
li $v0, 0x4
syscall
move $a0, $t2
li $v0, 0x1
syscall
la $a0, max
li $v0, 0x4
syscall
move $a0, $t3
li $v0, 0x1
syscall
li $v0, 0xa
syscall