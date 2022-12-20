%{
    #include <stdio.h>
%}

%%
[a-z]+ {printf("lower case\n");
        ECHO;
        printf("\nBegin yyterminate\n");
        yyterminate();
        printf("End of yyterminate\n");
        }
[a-zA-Z]+ {printf("Mixed case\n");}
%%

int main()
{
    yylex();
    printf("Closing Bye..\n");
}
