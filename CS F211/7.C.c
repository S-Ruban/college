#include <stdio.h>
int max(int x, int y);
int main()
{
	int N, M, i, j, top = -1, ma, tma = 0 ;
	int stack[1001];
	scanf("%d %d", &N, &M);
	int park[N+2][M+2];
	for (i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			scanf("%d", &park[i][j]);
			if(i > 1 && park[i][j] == 1)
				park[i][j] += park[i-1][j];
		}	
	}
	for(i = 1; i <= N; i++)
	{
		ma = 0 ;
		top = -1 ;
		for (j = 1; j <= M; j++)
		{
			while (top >= 0 && park[i][j] <= park[i][stack[top]])
			{
				if (!top)
					ma = max(ma, park[i][stack[top]]*(j-1));
				else
					ma = max(ma, park[i][stack[top]]*(j-stack[top-1]-1));
				top-- ;
			}
			stack[++top] = j ;
		}
		while (top != -1)
		{
			if (!top)
				ma = max(ma, park[i][stack[top]]*M);
			else
				ma = max(ma, park[i][stack[top]]*(M-stack[top-1]));
			top-- ;
		}
		if(ma > tma)
			tma = ma ;
	}
	printf("%d", tma);
}
int max(int x, int y)
{
	if(x > y)
		return x ;
	return y ;
}
