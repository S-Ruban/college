#include <stdio.h>
int main()
{
	int T, i, j, n, s, cap = 0, mc = 0 ;
	char c[9999];
	scanf("%d", &T);
	T++ ;
	while(T--)
	{
		n = 0 ;
		scanf("%c ", &c);
		if(c[0] == 'E')
		{
			scanf("%d", &n);
			cap += n ;
		}
		else
		{
			scanf("%d ", &n);
			for(j = 0; j < n-1; j++)
				scanf("%d", &s);
			scanf("%d", &s);
			cap -= n ;
		}
		if(cap > mc)
			mc = cap ;
		scanf("%d");
	}
	printf("%d", mc);
}
