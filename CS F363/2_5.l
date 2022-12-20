%{
#include <stdio.h>
%}
%%
. {printf("1");}
%%
main() {
yylex();
}

