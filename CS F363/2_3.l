%{
#include <stdio.h>
%}
%%
ab* printf("1");
d*c printf("0");
%%
main() {
yylex();
}

