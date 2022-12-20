#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct Node
{
	int val;
	struct Node *left ;
	struct Node *right ;
};
struct Node *root = NULL;
void postorder(struct Node *r);
struct Node *insert(struct Node *r, int x);
int search(struct Node *r, int x);
int post[10000];
int i, c = 0 ;
int main()
{
	int N, A ;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &A);
		if(!search(root, A))
		{
			root = insert(root, A);
			c++ ;
		}
	}
	i = 0 ;
	postorder(root);
	for(i = 0; i < c-1; i++)
		printf("%d ", post[i]);
	printf("%d", post[c-1]);
}
void postorder(struct Node *r)
{
	if(r == NULL)
		return ;
	postorder(r->left);
	postorder(r->right);
	post[i++] = r->val ;
}
struct Node *insert(struct Node *r, int x)
{
	if (r == NULL)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->val = x ;
		temp->left = NULL ;
		temp->right = NULL;
		return temp ;
	}
	if (x < r->val)
		r->left = insert(r->left, x);
	else
		r->right = insert(r->right, x);
	return r ;
}
int search(struct Node *r, int x)
{
	if(r == NULL)
		return FALSE ;
	if(r->val == x)
		return TRUE ;
	if(r->val > x)
		return search(r->left, x);
	else
		return search(r->right, x);
}
