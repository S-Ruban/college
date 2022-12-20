#include <stdio.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
int main()
{
	int M, N, i, c = 0 ;
	scanf("%d%d", &M, &N);
	int P[N];
	for(i = 0; i < N; i++)
		scanf("%d", &P[i]);
	qsort(P, N, sizeof(int), sort);
	for(i = 0; i < N; i++)
	{
		c += P[i];
		if(c > M)
			break ;
	}
	printf("%d", i);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
