#include <stdio.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
int main()
{
	int N, k1, k2, i, j, c = 0 ;
	scanf("%d %d %d", &N, &k1, &k2);
	int x[N], y[N], d[N];
	for(i = 0; i < N; i++)
		scanf("%d", &x[i]);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &y[i]);
		d[i] = x[i] - y[i];
	}
	qsort(d, N, sizeof(int), sort);
	for(i = 0; i < N-1; i++)
	{
		for(j = i+1; j < N; j++)
		{
			if(d[i]+d[j] > k2-k1)
				break ;
		}
		c += (N-j);
	}
	printf("%d", c);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
