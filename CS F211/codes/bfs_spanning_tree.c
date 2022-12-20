#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	struct node *next ;
};
int e, f ;
void print(struct node *vertex);
void push(struct node **vertex, int x);
void bfs(int v, bool vis[], struct node *n[], int q[], struct node *tree[]);
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	struct node *g[N], *bfsst[N];
	bool visited[N];
	int queue[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		bfsst[i] = NULL ;
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
		printf("BFS Spanning Tree obtained starting from %d : \n", i);
		for(j = 0; j < N; j++)
		{
			visited[j] = false ;
			bfsst[j] = NULL ;
		}
		bfs(i, visited, g, queue, bfsst);
		for(j = 0; j < N; j++)
		{
			if(bfsst[j] != NULL)
			{
				printf("%d -> ", j);
				print(bfsst[j]);
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
void bfs(int v, bool vis[], struct node *n[], int q[], struct node *tree[])
{
	e = 0 ;
	f = 0 ;
	q[e++] = v ;
	vis[v] = true ;
	while(f < e)
	{
		struct node *ptr = n[q[f]];
		int l = q[f++];
		while(ptr != NULL)
		{
			if(!vis[ptr->dest])
			{
				q[e++] = ptr->dest ;
				vis[ptr->dest] = true ;
				push(&tree[l], ptr->dest);
			}
			ptr = ptr->next ;
		}
	}
}
