%{
    #include "y.11_1.h"
%}

%%
[0-9]+ {yylval.ival = atoi(yytext); return NUM;}
[-+*/] {return *yytext;}
[\n] return;
%%
