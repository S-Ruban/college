#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int data ;
	struct node *next ;
};
struct node *stack = NULL ;
void print();
void push(int x);
int peek();
int pop();
int count = 0 ;
int main()
{
	if(count == 0)
		printf("empty\n");
	push(1);
	if(count == 0)
		printf("empty\n");
	printf("%d\n", pop());
	if(count == 0)
		printf("empty\n");
}
void print()
{
	struct node *ptr = stack ;
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
	if(stack == NULL)
		ptr->next = NULL ;
	else
		ptr->next = stack ;
	stack = ptr ;
	count++ ;
}
int peek()
{
	return stack->data ;
}
int pop()
{
	int p = peek();
	struct node *ptr = stack ;
	stack = ptr->next ;
	free(ptr);
	count-- ;
	if(count == 0)
		stack = NULL ;
	return p ;
}
