#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int dest ;
	double prob ;
	struct node *next ;
};
void push(struct node **vertex, int x, double d);
void dfs(int s, int v, bool vis[], struct node *n[], double p[s][2]);
void merge(int s, double arr[s][2], int l, int m, int r);
void sort(int s, double arr[s][2], int l, int r);
int main()
{
	int N, E, S, i, Wi, Wj ;
	double pij ;
	scanf("%d %d %d", &N, &E, &S);
	struct node *g[N];
	bool visited[N];
	double prob[N][2];
	for(i = 0; i < N; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		prob[i][0] = i ;
		prob[i][1] = 0.0f ;
	}
	prob[S][1] = 1.0f ;
	for(i = 0; i < E; i++)
	{
		scanf("%d %d %lf", &Wi, &Wj, &pij);
		push(&g[Wi], Wj, pij);
	}
	dfs(N, S, visited, g, prob);
	sort(N, prob, 0, N-1);
	/*printf("\n");
	for(i = 0; i < N; i++)
		printf("%d %0.2lf\n", (int)prob[i][0], prob[i][1]);*/
	for(i = 0; i < N; i++)
		printf("%d ", (int)prob[i][0]);
}
void push(struct node **vertex, int x, double d)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->dest = x ;
	ptr->prob = d ;
	if(vertex == NULL)
		ptr->next = NULL ;
	else
		ptr->next = (*vertex);
	(*vertex) = ptr ;
}
void dfs(int s, int v, bool vis[], struct node *n[], double p[s][2])
{
	vis[v] = true ;
	//printf("%d ", v);
	struct node *ptr = n[v];
	double z = 0.0f ;
	while(ptr != NULL)
	{
		if(!vis[ptr->dest])
		{
			p[ptr->dest][1] = p[v][1]*ptr->prob ;
			dfs(s, ptr->dest, vis, n, p);
		}
		z += ptr->prob ;
		ptr = ptr->next ;
	}
	p[v][1] = p[v][1]*(1.0f-z);
}
void merge(int s, double arr[s][2], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	double a1[n1][2], a2[n2][2];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i][1] > a2[j][1])
		{
			arr[k][0] = a1[i][0];
			arr[k++][1] = a1[i++][1];
		}
		else if(a1[i][1] < a2[j][1])
		{
			arr[k][0] = a2[j][0];
			arr[k++][1] = a2[j++][1];
		}
		else
		{
			if(a1[i][0] < a2[i][0])
			{
				arr[k][0] = a1[i][0];
				arr[k++][1] = a1[i++][1];
			}
			else
			{
				arr[k][0] = a2[j][0];
				arr[k++][1] = a2[j++][1];
			}
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k++][1] = a1[i++][1];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k++][1] = a2[j++][1];
	}
}
void sort(int s, double arr[s][2], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
