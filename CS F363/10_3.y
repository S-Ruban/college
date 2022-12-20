%{
    #include <stdio.h>
    #include <math.h>
    int zerocount = 0; int onecount = 0;
%}

%union
{
    struct {int zc; int oc;} t ;
}

%%
S:N {return;}
N:L {$<t.zc>$ = $<t.zc>1; $<t.oc>$ = $<t.oc>1;
     zerocount = $<t.zc>$; onecount = $<t.oc>$;}
L: L B {$<t.zc>$ = $<t.zc>1 + $<t.zc>2; $<t.oc>$ = $<t.oc>1 + $<t.oc>2;}
L: B {$<t.zc>$ = $<t.zc>1; $<t.oc>$ = $<t.oc>1;}
B: '1' {$<t.zc>$ = 0; $<t.oc>$ = 1;}
B: '0' {$<t.zc>$ = 1; $<t.oc>$ = 0;}
%%

void main()
{
    printf("Give the binary string: ");
    yyparse();
    printf("Number of zeroes: %d and number of ones : %d\n", zerocount, onecount);
    exit(0);
}

void yyerror()
{
    printf("Syntax error");
    exit(0);
}
