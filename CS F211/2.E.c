#include <stdio.h>
int bpow(int x, int y);
int main()
{
	int N, K, i, j, x ;
	scanf("%d %d", &N, &K);
	char c[N];
	scanf("%s", c);
	for(i = 0; i < bpow(N, K); i++)
	{
		for(x = 0, j = i; x < K; x++, j = (j-(j%N))/N)
			printf("%c", c[j%N]);
		printf("\n");
	}
}
int bpow(int x, int y)
{
	if(y == 0)
		return 1 ;
	if(y&1)
		return x*bpow(x, y/2)*bpow(x, y/2);
	else
		return bpow(x, y/2)*bpow(x, y/2);
}
