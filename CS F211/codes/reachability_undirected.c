#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
void print(struct node *vertex);
void push(struct node **vertex, int x);
void dfs(int v, bool vis[], struct node *n[]);
bool reachable(int u, int v, bool vis[], struct node *n[]);
int main()
{
	int N, M, U, V, i, j, A, B ;
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
		push(&g[V], U);
	}
	scanf("%d %d", &A, &B);
	if(reachable(A, B, visited, g))
		printf("%d and %d are connected.", A, B);
	else
		printf("%d and %d are not connected.", A, B);
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
void dfs(int v, bool vis[], struct node *n[])
{
	vis[v] = true ;
	printf("%d ", v);
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
			dfs(ptr->dest, vis, n);
		ptr = ptr->next ;
	}
}
bool reachable(int u, int v, bool vis[], struct node *n[])
{
	vis[u] = true ;
	if(u == v)
		return true ;
	struct node *ptr = n[u];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
			return reachable(ptr->dest, v, vis, n);
	}
	return false ;
}
