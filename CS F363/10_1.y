%{
    #include <stdio.h>
    #include <math.h>
%}

%%
S:N {return;}
N:L {printf("Equivalent Decimal Number is: %d\n", $1);}
L:L B {$$ = $1*2 + $2;}
L:B {$$ = $1;}
B: '1' {$$=1;}
B: '0' {$$=0;}
%%

void main()
{
    printf("Give the binary integer: ");
    yyparse();
    exit(0);
}

void yyerror()
{
    printf("Syntax error");
    exit(0);
}
