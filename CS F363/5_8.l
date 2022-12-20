%{
    #include <math.h>
%}
%s expect
%%
expect-floats   BEGIN(expect);
<expect>[0-9]+"."+[0-9] {
                printf("found a float, = %f\n",
                atof(yytext));
                }
"abc"   {printf("Ok GOOD");}
%%

int main()
{
    yylex();
}
