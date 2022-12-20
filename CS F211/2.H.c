#include <stdio.h>
int main()
{
	long long N, S = 0, i, j = 1, A ;
	scanf("%lld", &N);
	for(i = 2; i < N+2; i++)
	{
		scanf("%d", &A);
		S += A*j ;
		(i&(i-1)) ?  : j++ ;
	}
	printf("%lld", S);
}
