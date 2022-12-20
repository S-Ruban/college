%{
    #include <stdio.h>
%}

%%
stop {return;}
start {return;}
%%

int main()
{
    yylex();
    printf("%s\n", yytext);
    printf("%d", yyleng);
}

