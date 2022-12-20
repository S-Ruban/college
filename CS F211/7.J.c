#include <stdio.h>
long long hash(long long x);
int main()
{
	int N, i ;
	scanf("%d", &N);
	long long A[N];
	for(i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	while(N > 1)
	{
		//printf("N : %d\n", N-(N/2));
		for(i = 0; i < N-(N/2)-1; i++)
			A[i] = hash(A[2*i]*A[2*i+1]);
		if(N&1)
			A[N-(N/2)-1] = hash(A[N-1]);
		else
			A[N-(N/2)-1] = hash(A[N-2]*A[N-1]);
		/*for(i = 0; i < N-(N/2); i++)
			printf("%d ", A[i]);
		printf("\n");*/
		N = N-(N/2);
	}
	printf("%lld", A[0]);
}
long long hash(long long x)
{
	return ((x%65535)*((x%65535)+13))%65535 ;
}
