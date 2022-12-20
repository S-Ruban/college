#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int val;
	struct Node *left ;
	struct Node *right ;
};
int e, f ;
struct Node* queue[1000];
struct Node *bst = NULL;
void inorder(struct Node *r);
void preorder(struct Node *r);
void postorder(struct Node *r);
void levelorder(struct Node *r);
struct Node *insert(struct Node *r, int x);
struct Node *minvaluenode(struct Node *r);
struct Node *delete(struct Node *r, int x);
bool search(struct Node *r, int x);
int main()
{
	bst = insert(bst, 8);
	bst = insert(bst, 3);
	bst = insert(bst, 1);
	bst = insert(bst, 6);
	bst = insert(bst, 7);
	bst = insert(bst, 10);
	bst = insert(bst, 14);
	bst = insert(bst, 4);
	bst = insert(bst, 69);
	printf("Inorder traversal: ");
	inorder(bst);
	printf("\n");
	printf("Preorder traversal: ");
	preorder(bst);
	printf("\n");
	printf("Postorder traversal: ");
	postorder(bst);
	printf("\n");
	printf("Levelorder traversal: ");
	levelorder(bst);
	printf("\n");
}
void inorder(struct Node *r)
{
	if (r != NULL)
	{
		inorder(r->left);
		printf("%d -> ", r->val);
		inorder(r->right);
	}
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
void postorder(struct Node *r)
{
	if(r == NULL)
		return ;
	postorder(r->left);
	postorder(r->right);
	printf("%d -> ", r->val);
}
void levelorder(struct Node *r)
{
	e = 0 ;
	f = 0 ;
	struct Node *ptr = bst ;
	while(ptr != NULL)
	{
		printf("%d -> ", ptr->val);
		if(ptr->left != NULL)
			queue[e++] = ptr->left ;
		if(ptr->right != NULL)
			queue[e++] = ptr->right ;
		ptr = queue[f++];
	}
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
struct Node *minvaluenode(struct Node *r)
{
	struct Node *cur = r;
	while ((cur != NULL) && (cur->left != NULL))
	{
		cur = cur->left ;
	}
	return cur ;
}
struct Node *delete(struct Node *r, int x)
{
	if (r == NULL)
		return r ;
	if (x < r->val)
		r->left = delete(r->left, x);
	else if (x > r->val)
		r->right = delete(r->right, x);
	else
	{
		if (r->left == NULL)
		{
			struct Node *temp = r->right;
			free(r);
			return temp;
		}
		else if (r->right == NULL) 
		{
		  struct Node *temp = r->left;
		  free(r);
		  return temp;
		}
		struct Node *temp = minvaluenode(r->right);
		r->val = temp->val;
		r->right = delete(r->right, temp->val);
	}
	return r ;
}
bool search(struct Node *r, int x)
{
	if(r == NULL)
		return false ;
	if(r->val == x)
		return true ;
	if(r->val > x)
		return search(r->left, x);
	else
		return search(r->right, x);
}
