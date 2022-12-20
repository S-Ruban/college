%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%%
; return SC;
if return IF;
then return THEN;
else return ELSE;
[a-z]+ return COND;
[(] return LP;
[)] return RP;
[ \t]+  ;
\n {return 0;}
. {return yytext[0];}
%%
