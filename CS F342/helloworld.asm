.data
hello: .asciiz "Hello World!"
.text
main:
la $a0, hello
li $v0, 0x4
syscall
li $v0, 0xa
syscall