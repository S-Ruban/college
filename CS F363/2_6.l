%{
#include <stdio.h>
%}
%%
.|\n {printf("1");}
%%
main() {
yylex(); }

