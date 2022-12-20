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
void merge(int s, int arr[s][2], int l, int m, int r);
void sort(int s, int arr[s][2], int l, int r);
int main()
{
	int N, i ;
	struct node *g[26];
	bool visited[26], stack[26], exists[26];
	char s[3];
	int freq[26][2];
	scanf("%d\n", &N);
	for(i = 0; i < 26; i++)
	{
		g[i] = NULL ;
		visited[i] = false ;
		stack[i] = false ;
		exists[i] = false ;
		freq[i][0] = i+65 ;
		freq[i][1] = 0 ;
	}
	for(i = 0; i < N; i++)
	{
		scanf("%[^\n]%*c", s);
		push(&g[(int)s[0] - 65], (int)s[2] - 65);
		exists[(int)s[0] - 65] = true ;
		exists[(int)s[2] - 65] = true ;
		freq[s[0] - 65][1]++ ;
	}
	if(cycle(visited, g, stack))
		printf("ALIENS BE CRAZY");
	else
	{
		sort(26, freq, 0, 25);
		for(i = 0; i < 26; i++)
		{
			if(exists[freq[i][0]-65])
				printf("%c", (char)freq[i][0]);
		}
	}
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
	for(x = 0; x < 26; x++)
	{
		if(dfs(x, vis, n, stk))
			return true ;
	}
	return false ;
}
void merge(int s, int arr[s][2], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][2], a2[n2][2];
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
			if(a1[i][0] < a2[j][0])
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
void sort(int s, int arr[s][2], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
