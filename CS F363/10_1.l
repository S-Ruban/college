%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.10_1.h"o

%}

%%
[01] return yytext[0];
[\n] return;
%%
