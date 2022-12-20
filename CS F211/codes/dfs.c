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
int main()
{
	int N, M, U, V, i, j ;
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
	for(i = 0; i < N; i++)
	{
		printf("DFS Traversal of the graph starting from %d : ", i);
		for(j = 0; j < N; j++)
			visited[j] = false ;
		dfs(i, visited, g);
		printf("\n");
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
