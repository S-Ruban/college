%{
    #include <stdio.h>
    int vowel = 0, cons = 0 ;
%}

%%
[aeiouAEIOU] vowel++ ;
[a-zA-Z]{-}[aeiouAEIOU] cons++ ;
\n return 1 ;
%%

int main()
{
    printf("Enter a string: ");
    yylex();
    printf("No of vowels: %d\n", vowel);
    printf("No of consonants: %d\n", cons);
}

// lex program to count vowels and consonants
