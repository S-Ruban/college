%{
    #include <stdio.h>
%}

%%
[a-zA-Z\t][a-zA-Z]* fprintf(yyout, "%s", yytext);
%%

int main()
{
    yyin = fopen("sample.txt", "r");
    yylex();
}
