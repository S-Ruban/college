%{
    #include <stdio.h>
%}

%%
\" while(input() != '"');
%%

int main()
{
    yylex();
}
