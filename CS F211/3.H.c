#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A, P, C, i, j, pi, pj ;
	scanf("%d %d %d", &A, &P, &C);
	int author[P], cite[P], pub[A];
	for(i = 0; i < P; i++)
	{
		author[i] = -1 ;
		cite[i] = 0 ;
		if(i < A)
			pub[i] = 0 ;
	}
	for(i = 0; i < P; i++)
	{
		scanf("%d", author[i]);
		pub[author[i]]++ ;
	}
	int* graph[A];
	for(i = 0; i < A; i++)
		graph[i] = malloc(pub[i]*sizeof(int));
	for(i = 0; i < C; i++)
	{
		scanf("%d %d", &pi, &pj);
		cite[pj]++ ;
	}
	for(i = 0; i < P; i++)
	{
		int* p = graph[author[i]];
		
	}
}
