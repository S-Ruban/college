#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
};
void inorder(struct Node *r, int arr[]);
void preorder(struct Node *r, int arr[]);
void postorder(struct Node *r, int arr[]);
int N, i, x, y ;
char p ;
int main()
{
	scanf("%d", &N);
	int a[N], A[N], B[N], C[N];
	long long S = 0 ;
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
	i = 0 ;
	preorder(bt[0], A);
	i = 0 ;
	postorder(bt[0], B);
	i = 0 ;
	inorder(bt[0], C);
	for(i = 0; i < N; i++)
	{
		if(A[i] > B[i])
			S = (S+(long long)((C[i])*(long long)(A[i]-B[i])))%MOD ;
		else
			S = (S+(long long)((C[i])*(long long)(B[i]-A[i])))%MOD ;
	}
	printf("%lld", S);
}
void inorder(struct Node *r, int arr[])
{
	if (r != NULL)
	{
		inorder(r->left, arr);
		arr[i++] = r->val ;
		inorder(r->right, arr);
	}
}
void preorder(struct Node *r, int arr[])
{
	if(r != NULL)
		arr[i++] = r->val ;
	else
		return ;
	preorder(r->left, arr);
	preorder(r->right, arr);
}
void postorder(struct Node *r, int arr[])
{
	if(r == NULL)
		return ;
	postorder(r->left, arr);
	postorder(r->right, arr);
	arr[i++] = r->val ;
}
