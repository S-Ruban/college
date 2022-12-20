#include <stdio.h>
#include <stdlib.h>
int M, N, i ;
int upper_bound(int arr[], int l, int h, int k);
int sort(const void * x, const void * y);
int main()
{
	scanf("%d %d", &M, &N);
	int m[M], n[N];
	for(i = 0; i < M; i++)
		scanf("%d", &m[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &n[i]);
	qsort(m, M, sizeof(int), sort);
	printf("\n");
	for(i = 0; i < N; i++)
		printf("%d ", upper_bound(m, 0, M-1, n[i]));
}
int upper_bound(int arr[], int l, int h, int k)
{
    if (l > h) 
        return l;  
    if (arr[(l+h)/2] <= k)
        return upper_bound(arr, (l+h)/2 + 1, h, k);  
    return upper_bound(arr, l, (l+h)/2 - 1, k);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
