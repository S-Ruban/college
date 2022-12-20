%%
yes {printf("Hello\n"); printf("good \n: ");}
%%
main()
{
yylex();
}
// to recognize pattern “yes”, and if found will print Hello and good; takes input from keyboard and output on to the monitor
