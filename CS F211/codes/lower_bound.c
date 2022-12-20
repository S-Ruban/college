#include <stdio.h>
int lower_bound(int arr[], int l, int h, int k);
int main()
{
	int n, i, v ;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &v);
	printf("%d", lower_bound(a, 0, n-1, v));
}
int lower_bound(int arr[], int l, int h, int k)
{
    if (l > h) 
        return l; 
    if (arr[(l+h)/2] >= k) 
        return lower_bound(arr, l, (l+h)/2 - 1, k);   
    return lower_bound(arr, (l+h)/2 + 1, h, k);
}
