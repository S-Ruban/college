#include <stdio.h>
int main()
{
	int N, M, i, j ;
	scanf("%d %d", &N, &M);
	char s[N], t[M];
	scanf("%s %s", s, t);
	int lcs[N+1][M+1];
	for(i = 0; i <= N; i++)
	{
		for(j = 0; j <= M; j++)
			lcs[i][j] = 0 ;
	}
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			if(s[i-1] == t[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];
			else
			{
				if(lcs[i-1][j] > lcs[i][j-1])
					lcs[i][j] = lcs[i-1][j];
				else
					lcs[i][j] = lcs[i][j-1];
			}
		}
	}
	printf("%d", lcs[N][M]);
}
