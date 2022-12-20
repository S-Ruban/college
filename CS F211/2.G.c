#include <stdio.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
int main()
{
	int N, B ;
	scanf("%d", &N);
	int i, j = N-1, c = 0 ;
	int s[N];
	for(i = 0; i < N; i++)
		scanf("%d", &s[i]);
	scanf("%d", &B);
	qsort(s, N, sizeof(int), sort);
	i = 0 ;
	while(i <= j)
	{
		if(s[i]+s[j] <= B)
			i++ ;
		j-- ;
		c++ ;
	}
	printf("%d", c);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
