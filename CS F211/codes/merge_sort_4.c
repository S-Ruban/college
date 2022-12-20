#include <stdio.h>
void merge(int s, int arr[s][4], int l, int m, int r);
void sort(int s, int arr[s][4], int l, int r);
int main()
{
	int n, i ;
	scanf("%d", &n);
	int a[n][4];
	printf("\n");
	for(i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	sort(n, a, 0, n-1);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
}
void merge(int s, int arr[s][4], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][3], a2[n2][3];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
		a1[i][2] = arr[l+i][2];
		a1[i][3] = arr[l+i][3];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
		a2[i][2] = arr[m+1+i][2];
		a2[i][3] = arr[m+1+i][3];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i][2] < a2[j][2])
		{
			arr[k][0] = a1[i][0];
			arr[k][1] = a1[i][1];
			arr[k][2] = a1[i][2];
			arr[k++][3] = a1[i++][3];
		}
		else
		{
			arr[k][0] = a2[j][0];
			arr[k][1] = a2[j][1];
			arr[k][2] = a2[j][2];
			arr[k++][3] = a2[j++][3];
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k][1] = a1[i][1];
		arr[k][2] = a1[i][2];
		arr[k++][3] = a1[i++][3];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k][1] = a2[j][1];
		arr[k][2] = a2[j][2];
		arr[k++][3] = a2[j++][3];
	}
}
void sort(int s, int arr[s][4], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
