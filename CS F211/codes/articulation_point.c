#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
int time = 0 ;
void print(struct node *vertex);
void push(struct node **vertex, int x);
void dfs(int v, bool vis[], struct node *n[], int disc[], int low[], int parent[], bool cut[]);
int min(int x, int y);
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N], ap[N];
	int d[N], l[N], p[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		p[N] = -1 ;
		ap[N] = false ;
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
			dfs(i, visited, g, d, l, p, ap);
	}
	for(i = 0; i < N; i++)
	{
		if(ap[i])
			printf("%d ", i);
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
void dfs(int v, bool vis[], struct node *n[], int disc[], int low[], int parent[], bool cut[])
{
	int c = 0 ;
	vis[v] = true ;
	low[v] = disc[v] = ++time ;
	time++ ;
	struct node *ptr = n[v];
	while(ptr != NULL)
	{
		int x = ptr->dest ;
		if(!vis[x])
		{
			c++ ;
			parent[x] = v ;
			dfs(x, vis, n, disc, low, parent, cut);
			low[v] = min(low[v], low[x]);
			if((parent[v] == -1) && (c > 1))
				cut[v] = true ;
			if((parent[v] != -1) && (low[x] > disc[v]))
				cut[v] = true ;
		}
		else if(x != parent[v])
				low[v] = min(low[v], disc[x]);
		ptr = ptr->next ;
	}
}
int min(int x, int y)
{
	if(x > y)
		return y ;
	else
		return x ;
}
