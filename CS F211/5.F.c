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
void bfs(int v, bool vis[], struct node *n[], int q[]);
void merge(int arr[], int l, int m, int r);
void sort(int arr[], int l, int r);
int N, M, U, V, i, j ;
int main()
{
	scanf("%d %d", &N, &M);
	struct node *g[N];
	bool visited[N];
	int queue[N];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		queue[i] = 100001 ;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U-1], V-1);
		push(&g[V-1], U-1);
	}
	bfs(0, visited, g, queue);
	for(j = 0; j < N; j++)
		printf("%d ", queue[j]);
	printf("\n");
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
void bfs(int v, bool vis[], struct node *n[], int q[])
{
	e = 0 ;
	f = 0 ;
	q[e++] = v ;
	vis[v] = true ;
	while(f < e)
	{
		int i ;
		for(i = 0; i < N; i++)
			printf("%d ", q[i]);
		printf("\n");
		sort(q, f, e);
		struct node *ptr = n[q[f++]];
		while(ptr != NULL)
		{
			if(!vis[ptr->dest])
			{
				q[e++] = ptr->dest ;
				vis[ptr->dest] = true ;
			}
			ptr = ptr->next ;
		}
	}
}
void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1], a2[n2];
	for(i = 0; i < n1; i++)
		a1[i] = arr[l+i];
	for(i = 0; i < n2; i++)
		a2[i] = arr[m+1+i];
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i] < a2[j])
			arr[k++] = a1[i++];
		else
			arr[k++] = a2[j++];
	}
	while(i < n1)
	{
		arr[k++] = a1[i++];
	}
	while(j < n2)
	{
		arr[k++] = a2[j++];
	}
}
void sort(int arr[], int l, int r)
{
	if(l < r)
	{
		sort(arr, l, (l+r)/2);
		sort(arr, (l+r)/2 + 1, r);
		merge(arr, l, (l+r)/2, r);
	}
}
