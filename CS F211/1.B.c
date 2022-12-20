#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int data ;
	struct node *next ;
	struct node *prev ;
};
struct node *S  = NULL ;
int N ;
void print();
void push(char x);
bool palindrome();
int main()
{
	scanf("%d\n", &N);
	char b ;
	scanf("%c", &b);
	while(b != '\n')
	{
		push(b);
		scanf("%c", &b);
	}
	if(palindrome())
		printf("PALINDROME");
	else
		printf("NOT A PALINDROME");
}
void print()
{
	struct node *ptr = S ;
	while(ptr != NULL)
	{
		printf("%c", ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void push(char x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = x ;
	if(S == NULL)
	{
		ptr->next = NULL ;
		ptr->prev = NULL ;
		S = ptr ;
	}
	else
	{
		struct node *last = S ;
		while(last->next != NULL)
		{
			last = last->next ;
		}
		last->next = ptr ;
		ptr->prev = last ;
		ptr->next = NULL ;
	}
}
bool palindrome()
{
	struct node *last = S, *first = S ;
	int i = 0 ;
	while(last->next != NULL)
	{
		last = last->next ;
	}
	while(i <= N/2)
	{
		if(first->data != last->data)
			return false ;
		first = first->next ;
		last = last->prev ;
		i++ ;
	}
	return true ;
}
