%{
    #include <stdio.h>
%}

%%
begin |
beginning ECHO; REJECT
. printf("xx%c", *yytext);
%%

int main()
{
    yylex();
}
