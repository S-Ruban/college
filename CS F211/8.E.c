#include <stdio.h>
int val(int p, int in[], int n);
int postorder(int pre[], int in[], int n);
int inx = 0 ;
int arr[1000];
int main()
{
	int N, i ;
	scanf("%d", &N);
	int preorder[N], inorder[N];
	for(i = 0; i < N; i++)
		scanf("%d", &inorder[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &preorder[i]);
	postorder(preorder, inorder, N);
	for(i = 0; i < N-1; i++)
		printf("%d ", arr[i]);
	printf("%d", arr[N-1]);
}
int val(int p, int in[], int n)
{
	int i ;
	for (i = 0; i < n; i++)
	{
		if (in[i] == p)
			return i;
	}
	return -1 ;
}
int postorder(int pre[], int in[], int n)
{
	int root = val(pre[0], in, n);
	if(root != 0)
		postorder(pre+1, in, root);
	if(root != n-1)
		postorder(pre+root+1, in+root+1, n-root-1);
	arr[inx++] = pre[0];
}
