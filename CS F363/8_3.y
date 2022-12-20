%{
    #include <stdio.h>
    #include "y.tab.h"
    int yylex();
    void yyerror(const char *s);
%}

%token IF LP RP COND THEN ELSE SC

%%
var: IF LP COND RP THEN COND SC{printf("Valid declaration \n");}
    |IF LP COND RP THEN COND ELSE COND SC{printf("Valid declaration \n");}
    ;
%%

int yywrap() {return 1;}

void main()
{
    yyparse();
}

void yyerror(const char *s)
{
    printf("Invalid \n");
}
