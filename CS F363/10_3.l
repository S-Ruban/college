%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.10_3.h"
%}

%%
[01] return yytext[0];
[\n] return;
%%
