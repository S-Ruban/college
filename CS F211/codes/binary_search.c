#include <stdio.h>
#include <stdbool.h>
int search(int arr[], int l, int r, int k);
int main()
{
	int n, i, v ;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &v);
	if(search(a, 0, n-1, v) != -1)
		printf("%d", search(a, 0, n-1, v));
	else
		printf("%d does not exist in the sorted array.", v);
}
int search(int arr[], int l, int r, int k)
{
	if(l <= r)
	{
		if(arr[(l+r)/2] == k)
			return (l+r)/2 ;
		else if(arr[(l+r)/2] > k)
			return search(arr, l, (l+r)/2 - 1, k);
		else
			return search(arr, (l+r)/2 + 1, r, k);
	}
	return -1 ;
}
