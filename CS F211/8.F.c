#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
};
struct Node *lca(struct Node *r, int n1, int n2);
int main()
{
	struct Node *t ;
	int N, q, i, x, y ;
	char p ;
	scanf("%d %d", &N, &q);
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
	while(q--)
	{
		scanf("%d %d", &x, &y);
		t = lca(bt[0], bt[x]->val, bt[y]->val);
		for(i = 0; i < N; i++)
		{
			if(t->val == a[i])
			{
				printf("%d ", i);
				break ;
			}
		}
	}
}
struct Node *lca(struct Node *r, int n1, int n2)
{
	if(r == NULL)
		return NULL ;
	if((r->val == n1) || (r->val == n2))
		return r ;
	struct Node *lst = lca(r->left, n1, n2);
	struct Node *rst = lca(r->right, n1, n2);
	if((lst != NULL) && (rst != NULL))
		return r ;
	if(lst != NULL)
		return lst ;
	else
		return rst ;
}
