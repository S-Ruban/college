%{
    #include <stdio.h>
%}

%%
[a-zA-Z\t][a-zA-Z]* fprintf(yyout, " The token is : %s\n", yytext);
[0-9]* {}
[?%$#] {}
%%

int main()
{
    yyin = fopen("sample.txt", "r");
    yylex();
}

// skip numericals or special chars(#$%?) in the file
