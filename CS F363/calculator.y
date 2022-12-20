%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
%}

%token INTEGER

%%
s: program {return 1;}
program:
          line program
        | line
line:
          expr '\n' {printf("%d\n", $1);}
        | '\n'
expr:     expr '+' mulex {$$ = $1 + $3;}
        | expr '-' mulex {$$ = $1 - $3;}
        | mulex {$$ = $1;}
mulex:    mulex '*' term {$$ = $1 * $3;}
        | mulex '/' term {$$ = $1 / $3;}
        | term {$$ = $1;}
term:     '(' expr ')' {$$ = $2;}
        | INTEGER {$$ = $1;}
%%

void main()
{
    yyparse();
    return 0 ;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
    return ;
}
