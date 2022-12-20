%{
    #include <stdio.h>
%}

%%
begin printf("Compiler");
[a-z]+ printf("Compiler Design");
%%

int main()
{
    yylex();
}

// lex program to demonstrate priority the rule.(first rule)
