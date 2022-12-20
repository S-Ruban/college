#include <stdio.h>
#define MOD 1000000007
int main()
{
	long long N, x, pos, i, l = 0, r, m, c0 = 0, c1 = 0, c = 1 ;
	scanf("%lld %lld %lld", &N, &x, &pos);
	r = N ;
	long long a[N];
	for(i = 0; i < N; i++)
		a[i] = -1 ;
	while(l < r)
	{
		m = (l+r)/2 ;
		if(m <= pos)
		{
			l = m+1 ;
			a[m] = 0 ;
		}
		else
		{
			r = m ;
			a[m] = 1 ;
		}
	}
	for(i = 0; i < N; i++)
	{
		if(i == pos)
			continue ;
		if(a[i] == 1)
			c1++ ;
		else if(a[i] == 0)
			c0++ ;
	}
	for(i = x-1; i >= x-c0; i--)
		c = (c*i)%MOD ;
	for(i = N-x; i > N-x-c1; i--)
		c = (c*i)%MOD ;
	for(i = 1; i < N-c0-c1; i++)
		c = (c*i)%MOD ;
	printf("%lld", c);
}
