#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
	int height, freq ;
};
int max(int x, int y);
int height(struct Node *r);
struct Node *rr(struct Node *y);
struct Node *lr(struct Node *x);
int bf(struct Node *r);
struct Node* insert(struct Node* r, int x);
struct Node *minvaluenode(struct Node* r);
void preorder(struct Node *bst);
int d = 0 ;
int main()
{
	struct Node *avl = NULL;
	int N, a, i ;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a);
		avl = insert(avl, a);
	}
	preorder(avl);
	printf("%d", d);
}
int max(int x, int y)
{
	if(x > y)
		return x ;
	return y ;
}
int height(struct Node *r)
{
	if (r == NULL)
		return 0 ;
	return r->height ;
}
struct Node *rr(struct Node *y)
{
	struct Node *x = y->left ;
	struct Node *T2 = x->right ;
	x->right = y ;
	y->left = T2 ;
	y->height = max(height(y->left), height(y->right))+1 ;
	x->height = max(height(x->left), height(x->right))+1 ;
	return x ;
}
struct Node *lr(struct Node *x)
{
	struct Node *y = x->right ;
	struct Node *T2 = y->left ;
	y->left = x ;
	x->right = T2 ;
	x->height = max(height(x->left), height(x->right))+1 ;
	y->height = max(height(y->left), height(y->right))+1 ;
	return y ;
}
int bf(struct Node *r)
{
	if (r == NULL)
		return 0 ;
	return (height(r->left)-height(r->right));
}
struct Node* insert(struct Node* r, int x)
{
	if (r == NULL)
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->val = x ;
		temp->left = NULL ;
		temp->right = NULL ;
		temp->height = 1 ;
		temp->freq = 1 ;
		return temp ;
	}
	if (x < r->val)
		r->left = insert(r->left, x);
	else if (x > r->val)
		r->right = insert(r->right, x);
	else
	{
		r->freq++ ;
		return r ;
	}
	r->height = 1 + max(height(r->left),height(r->right));
	int balance = bf(r);
	if(balance > 1)
	{
		if(x < (r->left)->val)
			return rr(r);
		if(x > (r->left)->val)
		{
			r->left = lr(r->left);
			return rr(r);
		}
	}
	if(balance < -1)
	{
		if(x > (r->right)->val)
			return lr(r);
		if(x < (r->right)->val)
		{
			r->right = rr(r->right);
			return lr(r);
		}
	}
	return r ;
}
struct Node *minvaluenode(struct Node* r)
{
	struct Node* cur = r ;
	while (cur->left != NULL)
		cur = cur->left ;
	return cur ;
}
struct Node* delete(struct Node* r, int val)
{
	if (r == NULL)
		return r ;
	if (val < r->val)
		r->left = delete(r->left, val);
	else if(val > r->val)
		r->right = delete(r->right, val);
	else
	{
		if((r->left == NULL)||(r->right == NULL))
		{
			struct Node *temp ;
			if(r->left != NULL)
				temp = r->left ;
			else
				temp = r->right ;
			if (temp == NULL)
			{
				temp = r ;
				r = NULL;
			}
			else
				*r = *temp;
			free(temp);
		}
		else
		{
			struct Node* temp = minvaluenode(r->right);
			r->val = temp->val;
			r->right = delete(r->right, temp->val);
		}
	}
	if (r == NULL)
		return r ;
	r->height = 1 + max(height(r->left),height(r->right));
	int balance = bf(r);
	if(balance > 1)
	{
		if(bf(r->left) >= 0)
			return rr(r);
		else
		{
			r->left = lr(r->left);
			return rr(r);
		}
	}
	if(balance < -1)
	{
		if(bf(r->left) >= 0)
			return lr(r);
		else
		{
			r->right = rr(r->right);
			return lr(r);
		}
	}
	return r ;
}
void preorder(struct Node *r)
{
	if(r != NULL)
	{
		if(r->val > r->freq)
			d += r->freq ;
		else
			d += (r->freq-r->val);
		preorder(r->left);
		preorder(r->right);
	}
}
