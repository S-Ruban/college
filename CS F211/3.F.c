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
int sort(const void * x, const void * y);
int main()
{
	int N, M, U, V, i, j, p = 0, m ;
	scanf("%d %d", &N, &M);
	m = (4*N)/5 ;
	if(4*N % 5 != 0)
		m++ ;
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
	qsort(comp, scc, sizeof(int), sort);
	for(i = 1; i <= scc; i++)
	{
		p += comp[i-1];
		if(p >= m)
			break ;
	}
	printf("%d", i);
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
int sort(const void * x, const void * y)
{
	return (*(int*)y - *(int*)x);
}
