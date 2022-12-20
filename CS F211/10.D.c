#include <stdio.h>
int main()
{
	int N, W, i, j ;
	scanf("%d %d", &N, &W);
	int w[N], c[N], ks[N+1][W+1];
	for(i = 0; i < N; i++)
		scanf("%d", &w[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &c[i]);
	for(i = 0; i <= W; i++)
		ks[0][i] = 0 ;
	for(i = 0; i < N; i++)
		ks[i+1][0] = 0 ;
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= W; j++)
		{
			if(j-w[i-1] < 0)
				ks[i][j] = ks[i-1][j];
			else
			{
				if(ks[i-1][j] > ks[i-1][j-w[i-1]]+c[i-1])
					ks[i][j] = ks[i-1][j];
				else
					ks[i][j] = ks[i-1][j-w[i-1]]+c[i-1];
			}
		}
	}
	printf("%d", ks[N][W]);
}
