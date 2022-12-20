#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data ;
	struct node *next ;
};
struct node *ll = NULL ;
void print();
void push(int x);
void reverse();
int main()
{
	int n ;
	scanf("%d", &n);
	while(n != -1)
	{
		push(n);
		scanf("%d", &n);
	}
	reverse();
	print();
}
void print()
{
	struct node *ptr = ll ;
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
	if(ll == NULL)
	{
		ptr->next = NULL ;
		ll = ptr ;
	}
	else
	{
		struct node *last = ll ;
		while(last->next != NULL)
		{
			last = last->next ;
		}
		last->next = ptr ;
		ptr->next = NULL ;
	}
}
void reverse()
{
	struct node *prev = NULL, *cur = ll, *nxt = NULL ;
	while(cur != NULL)
	{
		nxt = cur->next ;
		cur->next = prev ;
		prev = cur ;
		cur = nxt ;
	}
	ll = prev ;
}
