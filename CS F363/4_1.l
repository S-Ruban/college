%{
    #include <stdio.h>
    int npink = 0, npin = 0, nink = 0 ;
%}

%%
pink {npink++;}
pin {npin++;}
ink {nink++;}
\n return;
%%

int main()
{
    yylex();
    printf("number of occurences of PINK %d\n", npink);
    printf("number of occurences of PIN %d\n", npin);
    printf("number of occurences of INK %d\n", nink);
}
