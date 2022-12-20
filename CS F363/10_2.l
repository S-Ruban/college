%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.10_2.h"
%}

%%
[ab] return yytext[0];
[\n] return;
%%
