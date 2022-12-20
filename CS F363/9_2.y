%{
    #include <stdio.h>
    #include <math.h>
%}

%token NUM

%%
S:E ';' {printf("\n"); return;}
E: E '+' T {printf("+ ");}
 | E '-' T {printf("- ");}
 | T
T: T '*' F {printf("* ");}
 | T '/' F {printf("/ ");}
 | F
F: '(' E ')'
 | NUM {printf("%d ", $1);}
%%

void main()
{
    printf("Give Infix expression: ");
    yyparse();
    exit(0);
}

void yyerror()
{
    printf("Expression error\n");
    exit(0);
}
