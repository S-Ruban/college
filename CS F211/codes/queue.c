#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data ;
	struct node *next ;
};
struct node *queue = NULL ;
void print();
void push(int x);
int pop();
int main()
{
	
}
void print()
{
	struct node *ptr = queue;
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void push(int x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node *));
	ptr->data = x ;
	if(queue == NULL)
		ptr->next = NULL ;
	else
		ptr->next = queue ;
	queue = ptr ;
}
int pop()
{
	struct node *ptr = queue ;
	if(ptr->next == NULL)
	{
		int d = ptr->data ;
		free(ptr);
		queue = NULL ;
		return d ;
	}
	while((ptr->next)->next != NULL)
	{
		ptr = ptr->next ;
	}
	int d = (ptr->next)->data ;
	ptr->next = NULL ;
	return d ;
}
