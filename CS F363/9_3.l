%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}

%%
[01] return yytext[0];
[\n] return;
%%
