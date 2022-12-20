%{
#include <stdio.h>
%}

%union {
	struct {
		int min;
		int max;
	} t;
}
%token <t> NUM

%%
S:LIST {
	$<t.max>$ = $<t.max>1;
	$<t.min>$ = $<t.min>1;
	printf("Max: %d\tMin: %d\n", $<t.max>$, $<t.min>$);
	return 0;
};
LIST:NUM_LIST';' {
	$<t.max>$ = $<t.max>1;
	$<t.min>$ = $<t.min>1;
};
NUM_LIST:NUM','NUM_LIST {
	if ($<t.max>3 < $<t.max>1) $<t.max>$ = $<t.max>1;
	else $<t.max>$ = $<t.max>3;

	if ($<t.min>1 < $<t.min>3) $<t.min>$ = $<t.min>1;
	else $<t.min>$ = $<t.min>3;
};
NUM_LIST:NUM {
	$<t.min>$ = $<t.min>1;
	$<t.max>$ = $<t.max>1;
};
%%

int main()
{
	yyparse();
	return 0;
}

void yyerror()
{
	printf("Invalid\n");
	exit(0);
}
