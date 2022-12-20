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
bool search(struct node *vertex, int n);
void dfs(int v, bool vis[], struct node *n[], struct node *tree[]);
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	struct node *g[N], *dfsst[N];
	bool visited[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		dfsst[i] = false ;
		visited[i] = false ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
		push(&g[V], U);
	}
	for(i = 0; i < N; i++)
	{
		printf("DFS Spanning Tree obtained starting from %d : \n", i);
		for(j = 0; j < N; j++)
		{
			visited[j] = false ;
			dfsst[j] = NULL ;
		}
		dfs(i, visited, g, dfsst);
		for(j = 0; j < N; j++)
		{
			if(dfsst[j] != NULL)
			{
				printf("%d -> ", j);
				print(dfsst[j]);
			}		
		}
	}
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
bool search(struct node *vertex, int n)
{
	struct node *ptr = vertex ;
	while(ptr != NULL)
	{
		if(ptr->dest == n)
			return true ;
		ptr = ptr->next ;
	}
	return false ;
}
void dfs(int v, bool vis[], struct node *n[], struct node *tree[])
{
	vis[v] = true ;
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
		{
			push(&tree[v], ptr->dest);
			dfs(ptr->dest, vis, n, tree);
		}		
		ptr = ptr->next ;
	}
}
