#include <stdio.h>
#define MOD 1000000007
int main()
{
	long long N, M, i, j ;
	scanf("%d %d", &N, &M);
	long long P[N], A[M];
	for(i = 0; i < N; i++)
		scanf("%d", &P[i]);
	for(i = 0; i < M; i++)
		scanf("%d", &A[i]);
	if(N >= 2*M-1)
	{
		long long pp[2*M-1];
		pp[0] = A[0];
		for(i = 1; i < M; i++)
			pp[i] = (pp[i-1]*A[i])%MOD ;
		pp[2*M-2] = A[M-1];
		for(i = 2*M-3; i >= M; i--)
			pp[i] = (pp[i+1]*A[i-M+1])%MOD ;
		for(i = 0; i < M-1; i++)
			P[i] = (P[i]*pp[i])%MOD ;
		for(i = N-1; i >= N-M+1; i--)
			P[i] = (P[i]*pp[i+2*M-N-1])%MOD ;
		for(i = M-1; i < N-M+1; i++)
			P[i] = (P[i]*pp[M-1])%MOD ;
	}
	else
	{
		for(i = 0; i < N-M+1; i++)
		{
			for(j = 0; j < M; j++)
				P[i+j] = (P[i+j]*A[j])%MOD ;
		}
	}
	for(i = 0; i < N; i++)
		printf("%d ", P[i]);
}
