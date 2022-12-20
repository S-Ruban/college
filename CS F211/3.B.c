#include <stdio.h>
void merge(int s, int arr[s][2], int l, int m, int r);
void sort(int s, int arr[s][2], int l, int r);
int upper_bound(int s, int arr[s][2], int t, int b, int k);
int main()
{
	int N, M, i, j, u ;
	scanf("%d %d", &N, &M);
	int a[N], b[M][2];
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < M; i++)
		scanf("%d %d", &b[i][0], &b[i][1]);
	sort(M, b, 0, M-1);
	for(j = 0; j < N; j++)
	{
		u = 0 ;
		for(i = 0; i < upper_bound(M, b, 0, M, a[j]); i++)
			u += b[i][1];
		printf("%d ", u);
	}
}
void merge(int s, int arr[s][2], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][2], a2[n2][2];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i][0] < a2[j][0])
		{
			arr[k][0] = a1[i][0];
			arr[k++][1] = a1[i++][1];
		}
		else
		{
			arr[k][0] = a2[j][0];
			arr[k++][1] = a2[j++][1];
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k++][1] = a1[i++][1];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k++][1] = a2[j++][1];
	}
}
void sort(int s, int arr[s][2], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
int upper_bound(int s, int arr[s][2], int t, int b, int k)
{
    if (t > b) 
        return t;  
    if (arr[(t+b)/2][0] <= k)
        return upper_bound(s, arr, (t+b)/2 + 1, b, k);  
    return upper_bound(s, arr, t, (t+b)/2 - 1, k);
}
