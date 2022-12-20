.data
.text
main:
  loop:
     add $t1, $t2, $t3
     sub $t2, $t1, $t3
     lw $t4, 8($t2)
     blt $t4, $0, exit
     addi $t2, $t2, 1
     b loop
exit:
  li $v0, 10
  syscal