yacc -d minmax.y
lex minmax.l
gcc y.tab.c lex.yy.c
./a.out