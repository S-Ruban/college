#include <stdio.h>
int main()
{
	int a[] = {10,8,6,4,2,0}, b[6], c[11];
	sort(a,b,c,10);
	int i ;
	for(i = 0; i < 6; i++)
		printf("%d", a[i]);
}
int sort(int A[], int B[], int C[], int k)
{
	int i, j ;
	for(i = 0; i <= k; i++)
		C[i] = 0 ;
	for(j = 0; j < (int)sizeof(A)/(int)sizeof(A[0]); j++)
		C[A[j]]++ ;
	for(i = 1; i <= k; i++)
		C[i] += C[i-1];
	for(j = (int)sizeof(A)/(int)sizeof(A[0])-1; j >= 0; i--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]-- ;
	}
}
