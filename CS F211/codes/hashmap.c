#include <stdio.h>
#include <stdlib.h>
#define CAP 10000
struct node
{
	int dest ;
	struct node *next ;
};
void print(struct node *vertex);
void push(struct node **vertex, int x);
int main()
{
	int N, i, a ;
	scanf("%d", &N);
	struct node *b[CAP];
	for(i = 0; i < CAP; i++)
		b[i] = NULL ;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a);
		push(&b[a%CAP], a);
	}
	for(i = 0; i < CAP; i++)
	{
		if(b[i] != NULL)
		{
			printf("b[%d] -> ", i);
			print(b[i]);
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
