%{
#include <stdio.h>
%}
%%
(ab)+ {printf("I");}
%%
main() {
yylex();
}

