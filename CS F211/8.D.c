#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
};
struct Node *n1, *n2, *t1, *t2 ;
void preorder(struct Node *r);
void delete(struct Node *p, struct Node *c, int k);
void swap(struct Node *p, struct Node *c, int x, int y);
int main()
{
	n1 = (struct Node *)malloc(sizeof(struct Node));
	n2 = (struct Node *)malloc(sizeof(struct Node));
	t1 = (struct Node *)malloc(sizeof(struct Node));
	t2 = (struct Node *)malloc(sizeof(struct Node));
	t1->left = NULL ;
	t1->right = NULL ;
	t2->left = NULL ;
	t2->right = NULL ;
	int N, T, i, x, y, A, B ;
	char p ;
	char str[17];
	scanf("%d %d", &N, &T);
	int a[N];
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
	scanf("%d");
	while(T--)
	{
		A = 0 ;
		B = 0 ;
		fgets(str, 16, stdin);
		if(((int)str[0])&1)
		{
			i = 5 ;
			while(str[i] != ' ')
			{
				A = A*10 + (int)(str[i++]-48);
			}
			i++ ;
			while(str[i] != '\0')
			{
				B = B*10 + (int)(str[i++]-48);
			}
			B = (B+38)/10 ;
			swap(NULL, bt[0], A, B);
			if(((n1->left)->val == A) && ((n2->left)->val == B))
			{
				t1->left = n1->left ;
				t2->left = n2->left ;
				n1->left = t2->left ;
				n2->left = t1->left ;
			}
			else if(((n1->left)->val == A) && ((n2->right)->val == B))
			{
				t1->left = n1->left ;
				t2->left = n2->right ;
				n1->left = t2->left ;
				n2->right = t1->left ;
			}
			else if(((n1->right)->val == A) && ((n2->left)->val == B))
			{
				t1->left = n1->right ;
				t2->left = n2->left ;
				n1->right = t2->left ;
				n2->left = t1->left ;
			}
			else if(((n1->right)->val == A) && ((n2->right)->val == B))
			{
				t1->left = n1->right ;
				t2->left = n2->right ;
				n1->right = t2->left ;
				n2->right = t1->left ;
			}
		}
		else
		{
			i = 7 ;
			while(str[i] != '\0')
			{
				A = A*10 + (int)(str[i++]-48);
			}
			A = (A+38)/10 ;
			delete(NULL, bt[0], A);
		}
	}
	printf("%d", diameter(bt[0])-1);
}
void preorder(struct Node *r)
{
	if(r != NULL)
		printf("%d -> ", r->val);
	else
		return ;
	preorder(r->left);
	preorder(r->right);
}
void delete(struct Node *p, struct Node *c, int k)
{
	if(c == NULL)
		return ;
	if(c->val == k)
	{
		if((p->left)->val == k)
			p->left = NULL ;
		else
			p->right = NULL ;
		return ;
	}
	else
	{
		delete(c, c->left, k);
		delete(c, c->right, k);
	}
}
void swap(struct Node *p, struct Node *c, int x, int y)
{
	if(c == NULL)
		return ;
	if(c->val == x)
		n1 = p ;
	else if(c->val == y)
		n2 = p ;
	else
	{
		swap(c, c->left, x, y);
		swap(c, c->right, x, y);
	}
}
int max(int x, int y)
{
	if(x > y)
		return x ;
	return y ;
}
int height(struct Node *r)
{
	if(r == NULL)
		return 0 ;
	return (1+max(height(r->left), height(r->right)));
}
int diameter(struct Node *r)
{
	if(r == NULL)
		return 0 ;
    return max(1+height(r->left)+height(r->right), max(diameter(r->left), diameter(r->right)));
}
