#include <stdio.h>
#include <string.h>
void inorder(char arr[][10], int index);
int N, i, j = 0, k, p ;
char t ;
int main()
{
	scanf("%d", &N);
	char A[N][10];
	for(i = 0; i < N; i++)
	{
		scanf("%s", A[i]);
		if(A[i][0] != '-')
			strrev(A[i]);	
	}
	i = 0 ;
	while(j != N-1)
	{
		i = 2*i + 1 ;
		j = 2*i ;
		for(k = i; k <= (i+j)/2; k++)
		{
			for(p = 0; p < 10; p++)
			{
				t = A[k][p];
				A[k][p] = A[i+j-k][p];
				A[i+j-k][p] = t ;
			}
		}
	}
	/*for(i = 0; i < N; i++)
		printf("%s ", A[i]);*/
	inorder(A, 0);
}
void inorder(char arr[][10], int index)
{
	if(index < N)
	{
		inorder(arr, 2*index+1);
		if(arr[index][0] != '-')
			printf("%s ", arr[index]);
		inorder(arr, 2*index+2);
	}
}
