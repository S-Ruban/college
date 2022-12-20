#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
int p = 0 ;
void push(struct node **vertex, int x);
void toposort(int v, bool vis[], struct node *n[], int s[]);
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N];
	int stack[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
	}
	for(i = 0; i < N; i++)
	{
		if(!visited[i])
			toposort(i, visited, g, stack);
	}
	for(i = N-1; i >= 0; i--)
		printf("%d ", stack[i]);
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
void toposort(int v, bool vis[], struct node *n[], int s[])
{
	vis[v] = true ;
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
			toposort(ptr->dest, vis, n, s);
		ptr = ptr->next ;
	}
	s[p++] = v ;
}
