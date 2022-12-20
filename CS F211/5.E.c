#include <stdio.h>
void merge(int arr[], int l, int m, int r);
void sort(int arr[], int l, int r);
int main()
{
	int N, k, i, j, a1, a2 ;
	scanf("%d %d", &N, &k);
	int d[N-1+k];
	scanf("%d %d", &a1, &a2);
	d[0] = a2 - a1 ;
	for(i = 1; i < N-1; i++)
	{
		scanf("%d", &a1);
		d[i] = a1 - a2 ;
		a2 = a1 ;
	}
	sort(d, 0, N-2);
	for(i = 0; i < k; i++)
	{
		sort(d, 0, N-2+i);
		d[N+i-1] = d[N+i-2]/2 ;
		d[N+i-2] -= d[N+i-1];
	}
	sort(d, 0, N-2+k);
	printf("%d", d[N-2+k]);
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
