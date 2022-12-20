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
void pop(struct node **vertex, int x);
bool dfs(int v, bool vis[], struct node *n[], int p);
bool cycle(bool vis[], struct node *n[]);
void merge(int s, int arr[s][3], int l, int m, int r);
void sort(int s, int arr[s][3], int l, int r);
int N, M, U, V, i, j, e ;
int main()
{
	scanf("%d %d", &N, &M);
	bool visited[N];
	struct node *mst[N];
	int edges[M][3];
	for(i = 0; i < N; i++)
	{
		mst[i] = NULL ;
		visited[i] = false ;
	}
	for(i = 0; i < M; i++)
		scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
	sort(M, edges, 0, M-1);
	printf("\n");
	for(i = 0; i < M; i++)
		printf("%d %d %d\n", edges[i][0], edges[i][1], edges[i][2]);
	e = 0 ;
	i = 0 ;
	printf("\n");
	while(e < N)
	{
		printf("%d\n", i+1);
		for(j = 0; j < N; j++)
			visited[j] = false ;
		push(&mst[edges[i][0]], edges[i][1]);
		push(&mst[edges[i][1]], edges[i][0]);
		for(j = 0; j < N; j++)
		{
			printf("%d -> ", j);
			print(mst[j]);
		}
		printf("\n");
		if(cycle(visited, mst))
		{
			for(j = 0; j < N; j++)
				visited[j] = false ;
			pop(&mst[edges[i][0]], edges[i][1]);
			printf("here");
			pop(&mst[edges[i][1]], edges[i][0]);
		}
		else
			e++ ;
		i++ ;
	}
	for(i = 0; i < N; i++)
	{
		printf("%d -> ", i);
		print(mst[i]);
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
void pop(struct node **vertex, int x)
{
	struct node *ptr = (*vertex);
	while(ptr != NULL)
	{
		if((ptr->next)->dest == x)
		{
			ptr->next = (ptr->next)->next ;
			break ;
		}
		ptr = ptr->next ;
	}
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
void merge(int s, int arr[s][3], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][3], a2[n2][3];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
		a1[i][2] = arr[l+i][2];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
		a2[i][2] = arr[m+1+i][2];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i][2] < a2[j][2])
		{
			arr[k][0] = a1[i][0];
			arr[k][1] = a1[i][1];
			arr[k++][2] = a1[i++][2];
		}
		else
		{
			arr[k][0] = a2[j][0];
			arr[k][1] = a2[j][1];
			arr[k++][2] = a2[j++][2];
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k][1] = a1[i][1];
		arr[k++][2] = a1[i++][2];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k][1] = a2[j][1];
		arr[k++][2] = a2[j++][2];
	}
}
void sort(int s, int arr[s][3], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
