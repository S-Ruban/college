%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
%}

%union{int ival; char *sval;}
%token <ival> INTEGER
%token <sval> STRING
%type <ival> COMPARE

%%
COMPARE: INTEGER '=' INTEGER {if($1 == $3) printf("EQUAL\n"); else printf("NOT EQUAL\n");}
        |STRING '=' STRING {if(!strcmp($1, $3)) printf("EQUAL\n"); else printf("NOT EQUAL\n");}
        ; 
%%

void main()
{
    yyparse();
}

void yyerror()
{

}
