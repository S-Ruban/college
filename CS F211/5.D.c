#include <stdio.h>
int main()
{
	int M, i, min, max, c1 = 0, c2 = 0 ;
	scanf("%d", &M);
	int Q[M];
	scanf("%d", &Q[0]);
	min = Q[0];
	max = Q[0];
	for(i = 1; i < M; i++)
	{
		scanf("%d", &Q[i]);
		if(Q[i] > max)
			max = Q[i];
		if(Q[i] < min)
			min = Q[i];
	}
	for(i = 0; i < M; i++)
	{
		if(Q[i] == min)
			c1++ ;
		if(Q[i] == max)
			c2++ ;
	}
	printf("%d %d", max-min, c1*c2);
}
