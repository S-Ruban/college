#include <stdio.h>
#include <stdlib.h>
struct node
{
	int dest ;
	struct node *next ;
};
void push(struct node **vertex, int x);
int main()
{
	int N, M, i, j, k = 0, e = 0, f = 0, t ;
	scanf("%d %d", &N, &M);
	int land[N][M], distance[N*M], queue[N*M], visited[N*M];
	struct node *g[N*M];
	for(i = 0; i < N*M; i++)
	{
		g[i] = NULL ;
		visited[i] = 0 ;
		distance[i] = 200002 ;
	}
	for(i = 0; i < N; i++)	// create a grid in the form of a graph
	{
		for(j = 0; j < M; j++, k++)
		{
			if(i == N-1)
			{
				if(j != M-1)
				{
					push(&g[k], k+1);
					push(&g[k+1], k);
				}
			}
			else if(j == M-1)
			{
				push(&g[k], k+M);
				push(&g[k+M], k);
			}
			else
			{
				push(&g[k], k+1);
				push(&g[k+1], k);
				push(&g[k], k+M);
				push(&g[k+M], k);
			}
		}
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			scanf("%d", &land[i][j]);
	}
	k = 0 ;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++, k++)
		{
			if(land[i][j] == 1)
			{
				distance[k] = 0 ;
				visited[k] = 1 ;
				queue[e++] = k ;
			}
		}
	}
	while(f < e)	// performing BFS to find the least distance
	{
		t = queue[f++];
		struct node *ptr = g[t];
		while(ptr != NULL)
		{
			if(visited[ptr->dest] == 0)
			{
				if(distance[ptr->dest] > distance[t]+1)
					distance[ptr->dest] = distance[t]+1 ;
				queue[e++] = ptr->dest ;
				visited[ptr->dest] = 1 ;
			}
			ptr = ptr->next ;
		}
	}
	for(i = 0; i < N*M; i++)
	{
		printf("%d", distance[i]);
		if((i+1)%M == 0)
		{
			if(i != N*M-1)
				printf("\n");
		}
		else
			printf(" ");
	}
}
void push(struct node **vertex, int x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->dest = x ;
	if(vertex == NULL)
		ptr->next = NULL ;
	else
		ptr->next = (*vertex);
	(*vertex) = ptr ;
}
