%{
    #include <stdio.h>
    int num = 0 ;
    int word = 0 ;
%}

%%
[0123456789]+ num = 1 ;
[a-zA-Z][a-zA-Z0-9]* word = 1 ;
\n return ;
%%

int main()
{
    yylex();
    if(num == 1) printf("This is a number\n");
    else
    printf("This is a word\n");
    return 0 ;
}
