#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
};
struct stack
{
	struct Node *n ;
	struct stack *next ;
};
void push(struct stack **top, struct Node *t);
struct Node *pop(struct stack **top);
int main()
{
	int N, i, x, y ;
	char p ;
	scanf("%d", &N);
	int a[N], A[N], B[N], C[N];
	struct Node *bt[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		bt[i] = (struct Node *)malloc(sizeof(struct Node));
		bt[i]->val = a[i];
		bt[i]->left = NULL ;
		bt[i]->right = NULL ;
	}
	for(i = 0; i < N-1; i++)
	{
		scanf("%d %d %c", &x, &y, &p);
		if(p == 'L')
			bt[x]->left = bt[y];
		else
			bt[x]->right = bt[y];
	}
	struct Node *cur = bt[0];
	struct stack *stk = NULL ;
	bool done = false ;
	while (!done)
	{
		if(cur !=  NULL)
		{
			push(&stk, cur);                                              
			cur = cur->left; 
		}
		else                                                             
		{
			if (stk != NULL)
			{
				cur = pop(&stk);
				printf("%d ", cur->val);
				cur = cur->right;
			}
			else
				done = true ;
		}
	}
}
void push(struct stack **top, struct Node *t)
{
	struct stack* nn = (struct stack *)malloc(sizeof(struct stack));
	nn->n  = t ;
	nn->next = (*top); 
	(*top) = nn ;
}
struct Node *pop(struct stack **top)
{
	struct Node *res ;
	struct stack *t ;
	t = *top ;
	res = t->n ;
	*top = t->next;
	free(t);
	return res ;
}
