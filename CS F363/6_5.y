%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token A B

%%
stmt: S
    ;
S:    A S B
    | A S
    |S B
    |
    ;
%%

void main()
{
    printf("Enter Expression: ");
    yyparse();
    printf("Valid Expression\n");
    exit(0);
}

void yyerror()
{
    printf("Invalid expression!\n");
    exit(0);
}
