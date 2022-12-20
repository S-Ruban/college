#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
void push(struct node **vertex, int x);
bool dfs(int v, bool vis[], struct node *n[], int p);
bool cycle(bool vis[], struct node *n[]);
int N, M, U, V, i ;
int main()
{
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
	if(cycle(visited, g))
		printf("The undirected graph has a cycle.");
	else
		printf("The undirected graph does not have a cycle.");
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
bool dfs(int v, bool vis[], struct node *n[], int p)
{
	vis[v] = true ;
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
		{
			if(dfs(ptr->dest, vis, n, v))
				return true ;
		}
		else if(ptr->dest != p)
			return true ;
		ptr = ptr->next ;
	}
	return false ;
}
bool cycle(bool vis[], struct node *n[])
{
	int i ;
	for(i = 0; i < N; i++)
	{
		if(!vis[i])
		{
			if(dfs(i, vis, n, -1))
				return true ;
		}
	}
	return false ;
}
