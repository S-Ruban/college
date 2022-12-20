%{
    #include <stdio.h>
    #include <stdlib.h>
    int i = 0;
%}
%token DT CM PTR L R SM ID OPN CLO
%%
s:expr {return;}
expr: RETURN ID OPN IDLIST CLO SM {i=1;}
RETURN: DT {i=1;}
IDLIST: DT ID EXP {i=1;}
        | {i=1;}
EXP: CM DT ID EXP {i=1;}
        | {i=1;}
%%

void main()
{
    printf("Declare function : ");
    yyparse();
    if(i == 1) printf("valid Declaration\n");
    exit(0);
}

void yyerror()
{
    printf("Declaration error");
    exit(0);
}
