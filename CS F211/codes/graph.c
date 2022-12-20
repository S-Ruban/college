#include <stdio.h>
#include <stdlib.h>
struct node
{
	int dest ;
	struct node *next ;
};
void print(struct node *vertex);
void push(struct node **vertex, int x);
int main()
{
	int N, M, U, V, i ;
	scanf("%d %d", &N, &M);
	struct node *g[N];
	for(i = 0; i < N; i++)
		g[i] = NULL ;
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &U, &V);
		push(&g[U], V);
		push(&g[V], U);
	}
	for(i = 0; i < N; i++)
	{
		printf("%d -> ", i);
		print(g[i]);
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
