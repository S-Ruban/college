#include <stdio.h>
#define MOD 1000000007
void merge(long long arr[], long long l, long long m, long long r);
void sort(long long arr[], long long l, long long r);
int main()
{
	long long N, D, i, Y = 0 ;
	scanf("%lld %lld", &N, &D);
	long long A[N];
	for(i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	while(D--)
	{
		sort(A, 0, N-1);
		Y += A[0];
		A[0] /= 3 ;
	}
	printf("%lld", Y);
}
void merge(long long arr[], long long l, long long m, long long r)
{
	long long n1 = m-l+1, n2 = r-m, i, j, k ;
	long long a1[n1], a2[n2];
	for(i = 0; i < n1; i++)
		a1[i] = arr[l+i];
	for(i = 0; i < n2; i++)
		a2[i] = arr[m+1+i];
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i] > a2[j])
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
void sort(long long arr[], long long l, long long r)
{
	if(l < r)
	{
		sort(arr, l, (l+r)/2);
		sort(arr, (l+r)/2 + 1, r);
		merge(arr, l, (l+r)/2, r);
	}
}
