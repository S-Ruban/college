#include <stdio.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
int main()
{
	int N, M, k, c = 0, i, j ;
	scanf("%d %d %d", &N, &M, &k);
	int A[N], S[M];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(j = 0; j < M; j++)
		scanf("%d", &S[j]);
	i = 0 ;
	j = 0 ;
	qsort(A, N, sizeof(int), sort);
	qsort(S, M, sizeof(int), sort);
	while((i < N) && (j < M))
	{
		if((S[j] >= A[i]-k) && (S[j] <= A[i]+k))
		{
			i++ ;
			j++ ;
			c++ ;
		}
		else
		{
			if(A[i] > S[j])
				j++ ;
			else
				i++ ;
		}
	}
	printf("%d", c);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
