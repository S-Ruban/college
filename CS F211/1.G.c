#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
int scc = 0, p = 0 ;
void print(struct node *vertex);
void push(struct node **vertex, int x);
void dfs(int v, bool vis[], struct node *n[], int c[]);
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N];
	int comp[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		comp[i] = 0 ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
		push(&g[V], U);
	}
	for(i = 0; i < N; i++)
	{
		if(!visited[i])
		{
			dfs(i, visited, g, comp);
			scc++ ;
		}
	}
	printf("%d\n", scc);
	for(i = 0; i < scc; i++)
		printf("%d ", comp[i]);
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
void dfs(int v, bool vis[], struct node *n[], int c[])
{
	vis[v] = true ;
	c[scc]++ ;
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
			dfs(ptr->dest, vis, n, c);
		ptr = ptr->next ;
	}
}
