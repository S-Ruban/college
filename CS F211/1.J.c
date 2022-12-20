#include <stdio.h>
#include <stdbool.h>
bool isSafe(int s, int v, int arr[s][s], int color[s], int clr);	// checking if its possible to visit next node and colour it
bool coloring(int s, int arr[s][s], int m, int color[s], int v);	// function to check if it is possible to colour the graph with m colours
int main()
{
	int N, M, U, V, i, j ;
	scanf("%d %d", &N, &M);
	int graph[N][N];
	int color[N];
	for(i = 0; i < N; i++)
	{
		for(j = i; j < N; j++)
		{
			graph[i][j] = false ;
			graph[j][i] = false ;
		}
	}
	while(M--)
	{
		scanf("%d %d", &U, &V);
		graph[U][V] = true ;
		graph[V][U] = true ;
	}
	if(coloring(N, graph, 2, color, 0))
	{
		for(i = 0; i < N; i++)
		{
			if(color[i]&1)
				printf("R");
			else
				printf("B");	
		}
	}
		
	else
		printf("NEED MORE COLOURS");	
}
bool isSafe(int s, int v, int arr[s][s], int color[s], int clr)
{
	int x ;
    for(x = 0; x < s; x++)
    {
        if((arr[v][x] == 1) && (clr == color[x]))
            return false;
    }
    return true;
}
bool coloring(int s, int arr[s][s], int m, int color[s], int v)
{
    if (v == s)
        return true;
    int c ;
    for (c = 1; c <= m; c++)	// checking for all colours from 1 to m
	{
        if (isSafe(s, v, arr, color, c))
		{
            color[v] = c;
            if (coloring(s, arr, m, color, v+1))	// greedy algo to colour graphs
                return true;
            color[v] = 0;
        }
    }
    return false;
}
