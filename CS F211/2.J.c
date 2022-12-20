#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
int e, f, C = 0, l = 0 ;
void print(struct node *vertex);
void push(struct node **vertex, int x);
void bfs(int v, bool vis[], struct node *n[], int q[], int d[]);
int main()
{
	int N, M, S, T, U, V, i, j ;
	scanf("%d %d %d %d", &N, &M, &S, &T);
	struct node *g[N];
	bool visited[N];
	int queue[N], dist[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		dist[i] = 0 ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
		push(&g[V], U);
	}
	bfs(S, visited, g, queue, dist);
	for(i = 0; i < N; i++)
		printf("%d ", queue[i]);
	printf("\n");
	for(i = 0; i < N; i++)
		printf("%d ", dist[queue[i]]);
	printf("\n%d", C);
}
void print(struct node *vertex)
{
	struct node *ptr = vertex ;
	while(ptr != NULL)
	{
		printf("%d ", ptr->dest);
		ptr = ptr->next ;
	}
	printf("\n");
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
void bfs(int v, bool vis[], struct node *n[], int q[], int d[])
{
	e = 0 ;
	f = 0 ;
	q[e] = v ;
	e++ ;
	vis[v] = true ;
	while(f < e)
	{
		int l = f ;
		struct node *ptr = n[q[f]];
		f++ ;
		while(ptr != NULL)
		{
			if(!vis[ptr->dest])
			{
				d[ptr->dest] = d[l] + 1 ;
				q[e] = ptr->dest ;
				e++ ;
				vis[ptr->dest] = true ;
			}
			ptr = ptr->next ;
		}
		f++ ;
	}
}
