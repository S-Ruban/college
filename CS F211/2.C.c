#include <stdio.h>
//#include <stdbool.h>
#define TRUE 1
#define FALSE 0
int main()
{
	int N, U, V, i, a = -1, b, m ;
	scanf("%d", &N);
	int w[N], g[N];
	int c[N];
	for(i = 0; i < N; i++)
	{
		w[i] = g[i] = 0 ;
		c[i] = FALSE ;
	}
	for(i = 0; i < (N*(N-1))/2-1; i++)
	{
		scanf("%d %d", &U, &V);
		w[U-1]++ ;
		g[U-1]++ ;
		g[V-1]++ ;
	}
	for(i = 1; i <= N; i++)
	{
		if(c[w[i-1]] == FALSE)
			c[w[i-1]] = TRUE ;
		else
			m = w[i-1];
		if(g[i-1] != N-1)
		{
			if(a == -1)
				a = i ;
			else
			{
				b = i ;
				break ;
			}
		}	
	}
	if(w[a-1] == w[b-1])
		printf("-1");
	else
	{
		if(w[a-1] == m)
			printf("%d %d", a, b);
		else
			printf("%d %d", b, a);
	}
}
