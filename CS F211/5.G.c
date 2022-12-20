#include <stdio.h>
void merge(int arr[], int l, int m, int r);
void sort(int arr[], int l, int r);
int main()
{
	int N, q, i, k ;
	scanf("%d %d", &N, &q);
	int a[N], sum[N];
	for(i = 0; i < N; i++)
	{
		sum[i] = 0 ;
		scanf("%d", &a[i]);
		sum[0] += a[i];
	}
	for(i = 0; i < N; i++)
	{
		sort(a, i, N-1);
		a[N-1] -= a[i] ;
		sum[i+1] = sum[i]-2*a[i];
	}
	while(q--)
	{
		scanf("%d", &k);
		printf("%d\n", sum[k]);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1], a2[n2];
	for(i = 0; i < n1; i++)
		a1[i] = arr[l+i];
	for(i = 0; i < n2; i++)
		a2[i] = arr[m+1+i];
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i] < a2[j])
			arr[k++] = a1[i++];
		else
			arr[k++] = a2[j++];
	}
	while(i < n1)
	{
		arr[k++] = a1[i++];
	}
	while(j < n2)
	{
		arr[k++] = a2[j++];
	}
}
void sort(int arr[], int l, int r)
{
	if(l < r)
	{
		sort(arr, l, (l+r)/2);
		sort(arr, (l+r)/2 + 1, r);
		merge(arr, l, (l+r)/2, r);
	}
}
