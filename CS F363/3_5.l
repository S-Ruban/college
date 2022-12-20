%{
    #include <stdio.h>
    int word = 0, num = 0 ;
%}

%%
[0-9]+ num++ ;
[0-9]+\.[0-9]* num++ ;
[a-zA-Z]+ word++ ;
.|\n {}
%%

int main()
{
    yyin = fopen("sample.txt", "r");
    yylex();
    printf("Number of words: %d\n", word);
    printf("Number of nums: %d\n", num);
}

// write a lex program to count the number of words and numbers
