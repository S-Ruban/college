.data
.text
main:
# blt $t0, $t1, main
# bgt $t0, $t1, main
# ble $t0, $t1, main
# bge $t0, $t1, main
# move $t0, $t1
# li $t0, 0x8d0320f4
# b $t0
# li $t0, 94249
# li $t1, 49
# rem $s2, $t0, $t1
bgez $t0, main
li $v0, 0xa
syscall