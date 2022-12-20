%{
    #include <stdio.h>
    #include "y.tab.h"
%}

letter [a-zA-Z]
digit [0-9]
dtype "int"|"char"|"float"|"double"|"void"|"long"

%%
({dtype})" " return DT;
({letter}|"_")({letter}|{digit}|"_")* return ID;
"(" return OPN;
")" return CLO;
";" return SM;
"." return CM;
"[" return L;
"]" return R;
"*" return PTR;
"\n" return;
. return *yytext;
%%
