%{
#include "y.tab.h"
extern union yylval;
%}

%%
[1-9][0-9]* {
	yylval.t.min = atoi(yytext);
	yylval.t.max = atoi(yytext);
	return NUM;
};
[,;\n] return *yytext;
. return yytext;
%%

int yywrap(){}