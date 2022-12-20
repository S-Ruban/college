%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    extern int yylval;
%}

letter [A-Za-z]
digit [0-9]

%%
{digit}+ {yylval = atoi(yytext); return NUM;}
("+"|"-"|"*"|"/") {return *yytext;}
. {return *yytext;}
%%
