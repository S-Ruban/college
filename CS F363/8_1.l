%{
    #include "y.tab.h"
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
%}

%%
[0-9]+ {yylval.ival = atoi(yytext); return INTEGER;}
[a-z]+ {yylval.sval = malloc(sizeof(char)*10); strcpy(yylval.sval, yytext); return STRING;}
"=" {return yytext[0];}
\n ;
%%
