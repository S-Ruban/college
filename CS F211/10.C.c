#include <stdio.h>
#define MOD 1000000007
int main()
{
	long long N, i, j ;
	scanf("%lld", &N);
	scanf("%c");
	char c[2*N-1];
	long long castle[N][N];
	for(i = 0; i < N; i++)
	{
		fgets(c, 2*N-1, stdin);
		for(j = 0; j < 2*N; j += 2)
		{
			if(c[j] == '.')
				castle[i][j] = 0 ;
			else
				castle[i][j] = -1 ;
		}
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if (castle[i][j] == -1)
				castle[i][j] = -1; 
  			else if (castle[i-1][j] > 0)
				castle[i][j] = (castle[i][j] + castle[i-1][j]);
  			else if (castle[i][j-1] > 0)
				castle[i][j] = (castle[i][j] + castle[i][j-1]);
		}
	}
	if((castle[0][0] == -1) || (castle[N-1][N-1] == -1))
		printf("0");
	else
		printf("%lld", castle[N-1][N-1]%MOD);
	printf("\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%lld ", castle[i][j]);
		printf("\n");
	}
}
