%{
    #include <stdio.h>
    int word = 0, line = 0, charec = 0, space = 0 ;
%}

%%
[a-zA-Z0-9]+ {word++; charec += yyleng;}
\n line++ ;
%%

int main()
{
    yyin = fopen("sample.txt", "r");
    yylex();
    printf("Number of words: %d\n", word);
    printf("Number of char: %d\n", charec);
    printf("Number of lines: %d\n", line);
    printf("Number of spaces: %d\n", space);
}

// write a lex program to count the number of words, chars and lines
