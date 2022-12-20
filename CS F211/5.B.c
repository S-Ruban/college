#include <stdio.h>
#define MOD 1000000007
long long decrypt(char d[]);
void merge(long long arr[], long long l, long long m, long long r);
void sort(long long arr[], long long l, long long r);
int main()
{
	long long N, k, i, revenue = 0 ;
	char D[150];
	scanf("%lld %lld", &N, &k);
	long long C[N];
	for(i = 0; i < N; i++)
	{
		scanf("%s", D);
		C[i] = decrypt(D);
	}
	sort(C, 0, N-1);
	for(i = 0; i < k; i++)
		revenue = (revenue+C[i])%MOD ;
	printf("%lld", revenue);
}
long long decrypt(char d[])
{
	long long money = 0, temp = 0, i = 0 ;
	while(d[i] != '\0')
	{
		if((d[i] >= '0') && (d[i] <= '9'))
			temp = (((temp*10)%MOD) + ((int)d[i]-48))%MOD ;
		else
		{
			money = (money + (temp%MOD))%MOD ;
			temp = 0 ;
		}
		i++ ;
		if(d[i] == '\0')
			money = (money + (temp%MOD))%MOD ;
	}
	return money ;
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
