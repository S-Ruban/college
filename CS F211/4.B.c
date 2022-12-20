#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data ;			
	struct node *next ;
	struct node *prev ;
};
struct node *head = NULL, *tail = NULL ;
void print();
void push(int x);
void eliminate();
int min(int x, int y);
int N, i, a, b, c ;
int main()
{
	scanf("%d %d %d", &N, &a, &b);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &c);
		push(c);
	}
	eliminate();
	print();
}
void print()
{
	struct node *ptr = head ;
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void push(int x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = x ;
	if(head == NULL)
	{
		head = ptr ;
		tail = ptr ;
		tail->next = NULL ;
	}
	else
	{
		tail->next = ptr ;
		ptr->prev = tail ;
		tail = ptr ;
		tail->next = NULL ;
	}
}
int min(int x, int y)
{
	return (x > y) ? y : x ;
}
void eliminate()
{
	
}
