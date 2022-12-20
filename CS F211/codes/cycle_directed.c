#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
void push(struct node **vertex, int x);
bool dfs(int v, bool vis[], struct node *n[], bool stk[]);
bool cycle(bool vis[], struct node *n[], bool stk[]);
int N, M, U, V, i ;
int main()
{
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N], stack[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		stack[i] = false ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
	}
	if(cycle(visited, g, stack))
		printf("The directed graph has a cycle.");
	else
		printf("The directed graph does not have a cycle.");
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
bool dfs(int v, bool vis[], struct node *n[], bool stk[])
{
	if(!vis[v])
	{
		vis[v] = true ;
		stk[v] = true ;
		struct node *ptr = n[v];
		while(ptr != NULL)
		{
			if((!vis[ptr->dest]) && (dfs(ptr->dest, vis, n, stk)))
				return true ;
			else if(stk[ptr->dest])
				return true ;
			ptr = ptr->next ;
		}
	}
	stk[v] = false ;
	return false ;
}
bool cycle(bool vis[], struct node *n[], bool stk[])
{
	int x ;
	for(x = 0; x < N; x++)
	{
		if(dfs(x, vis, n, stk))
			return true ;
	}
	return false ;
}
