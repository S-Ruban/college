#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
#define NEGINF -1e9
#define ZERO 0.0000000001
#define NEGZERO -0.0000000001
struct Node
{
	float val ;
	struct Node *left ;
	struct Node *right ;
	int height, freq ;
};
double mod(double x);
int max(int x, int y);
int height(struct Node *r);
struct Node *rr(struct Node *y);
struct Node *lr(struct Node *x);
int bf(struct Node *r);
struct Node* insert(struct Node* r, double x);
struct Node *minvaluenode(struct Node* r);
void preorder(struct Node *bst);
int s = 0 ;
int main()
{
	struct Node *avl = NULL;
	int N, x, y, i ;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		if(x == 0)
		{
			if(y > 0)
				avl = insert(avl, INF);
			else if(y < 0)
				avl = insert(avl, NEGINF);
		}
		else if(y == 0)
		{
			if(x > 0)
				avl = insert(avl, ZERO);
			else if(x < 0)
				avl = insert(avl, NEGZERO);
		}
		else
			avl = insert(avl, (double)y/(double)x);
	}
	preorder(avl);
	printf("%d", s);
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
struct Node* insert(struct Node* r, double x)
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
	if(mod(x - r->val) <= 0.00000000000000001)
	{
		r->freq++ ;
		return r ;
	}
	if (x < r->val)
		r->left = insert(r->left, x);
	else if (x > r->val)
		r->right = insert(r->right, x);
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
		s++ ;
		printf("%lf ", r->val);
		preorder(r->left);
		preorder(r->right);
	}
}
double mod(double x)
{
	if(x < 0)
		return (-1.0 * x);
	return x ;
}
