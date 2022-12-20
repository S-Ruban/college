%{
    #include <stdio.h>
    int npink = 0, npin = 0, nink = 0 ;
%}

%%
pink {npink++; printf("Matching pink:\n"); REJECT;}
pin {npin++; printf("Matching pin:\n"); REJECT}
ink {nink++; printf("Matching ink:\n"); REJECT}
\n return;
%%

int main()
{
    yylex();
    printf("number of occurences of PINK %d\n", npink);
    printf("number of occurences of PIN %d\n", npin);
    printf("number of occurences of INK %d\n", nink);
}
