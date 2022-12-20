#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
bool search(int arr[], int l, int r, int k);
int main()
{
	int N, q, t, i ;
	scanf("%d %d", &N, &q);
	int a[N];
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	qsort(a, N, sizeof(int), sort);
	while(q--)
	{
		scanf("%d", &t);
		if(search(a, 0, N-1, t))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
bool search(int arr[], int l, int r, int k)
{
	if(l <= r)
	{
		if(arr[(l+r)/2] == k)
			return true ;
		else if(arr[(l+r)/2] > k)
			return search(arr, l, (l+r)/2 - 1, k);
		else
			return search(arr, (l+r)/2 + 1, r, k);
	}
	return false ;
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
