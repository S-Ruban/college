%{
    #include <stdio.h>
%}

%%
"un" {printf("\nThe unput char is = ");
      ECHO;
     }
[a-z]+ {printf("Lower case is = ");
        ECHO; unput('n'); unput('u');
        printf("\n the token after unput is = ");
        ECHO;
       }
[a-zA-Z]+ {printf("\nMixed token is = ");
           ECHO;
          }
%%

int main()
{
    yylex();
}
