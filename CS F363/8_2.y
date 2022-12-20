%{
    // Check validity of assignment statements
    #include <stdio.h>
    #include <stdlib.h>
%}

%token ID NUMBER

%%
stmt: expr ;
    | expr: ID '=' ID ;
    | ID '=' NUMBER
    ;
%%

void main()
{
    printf("enter statement: ");
    yyparse();
    printf("valid statement\n");
    exit(0);
}

void yyerror()
{
    printf("invalid statement\n"); exit(0);
}
