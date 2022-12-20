%{
    #include <stdio.h>
%}

%union {int ival; double dval;}
%token <ival> INTEGER
%token <dval> NUMBER
%type <dval> sum

%%
stmt: sum;
sum: INTEGER '+' INTEGER { $$ = ((double)($1 + $3)); printf("%lf\n", $$);}
    | NUMBER '+' NUMBER { $$ = $1 + $3; printf("%lf\n", $$);}
    | '\n' {}
%%

void main()
{
    yyparse();
}

void yyerror()
{
    printf("Invalid expression!");
    exit(0);
}
