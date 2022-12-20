#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* ll = NULL ;
void print();
void push(int x);
void reverse(int e, int s);
int main()
{
    int N, k, i, x, y ;
    scanf("%d %d", &N, &k);
    int a[k], s[k];
    push(-999);
    for(i = 0; i < N; i++)
    {
    	scanf("%d", &x);
    	push(x);
	}
	for(i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
		if(i == 0)
			s[i] = a[i];
		else
			s[i] = s[i-1]+a[i];
		if(i == 0)
			reverse(2, s[i]+1);
		else
			reverse(s[i-1]+2, s[i]+1);
	}
	print();
}
void print()
{
    struct node* ptr = ll->next;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void push(int x)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = x ;
	if(ll == NULL)
	{
		ptr->next = NULL ;
		ll = ptr ;
	}
	else
	{
		struct node* last = ll ;
		while(last->next != NULL)
		{
			last = last->next ;
		}
		last->next = ptr ;
		ptr->next = NULL ;
	}
}
void reverse(int s, int e)
{
    struct node* prev = NULL;
    struct node* curr = ll ;
	int i ;
    for (i = 1; curr != NULL && i < s; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    struct node* start = curr;
    struct node* end = NULL;
    for (i = 1; curr != NULL && i <= e-s+1; i++)
    {
        struct node* next = curr->next;
 		curr->data *= (e-s+1);
        curr->next = end;
        end = curr;
        curr = next;
    }
    start->next = curr;
    if (prev != NULL)
        prev->next = end;
    else
        ll = end;
}
