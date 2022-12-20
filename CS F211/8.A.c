#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int val ;
	struct Node *left ;
	struct Node *right ;
	int level ;
};
void levelorder(struct Node *r);
struct Node* queue[1000];
int N, i, x, y, e, f ;
char p ;
bool flag = true ;
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
	bt[0]->level = 1 ;
	for(i = 0; i < N-1; i++)
	{
		scanf("%d %d %c", &x, &y, &p);
		if(p == 'L')
			bt[x]->left = bt[y];
		else
			bt[x]->right = bt[y];
		bt[y]->level = 1 + bt[x]->level ;
	}
	levelorder(bt[0]);
}
void levelorder(struct Node *r)
{
	e = 0 ;
	f = 0 ;
	struct Node *ptr = r ;
	while(ptr != NULL)
	{
		printf("%d -> ", ptr->val, ptr->level);
		if(f == N-1)
			return ;
		if(flag)
		{
			if(ptr->left != NULL)
				queue[e++] = ptr->left ;
			if(ptr->right != NULL)
				queue[e++] = ptr->right ;
		}
		else
		{
			if(ptr->right != NULL)
				queue[e++] = ptr->right ;
			if(ptr->left != NULL)
				queue[e++] = ptr->left ;
		}
		if(ptr->level != queue[f]->level)
			flag = !flag ;
		ptr = queue[f++];
	}
}
