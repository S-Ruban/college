#include <stdio.h>
#include <stdbool.h>
#include <string.h>
long long j ;
bool isprime(long long x);
void sieve(long long x, bool p[]);
int main()
{
	long long freq[10];
	for(j = 0; j < 10; j++)
		freq[j] = 0 ;
	long long A, B, t, f = 0, i ;
	scanf("%lld %lld", &A, &B);
	bool prime[B+1];
	memset(prime, true, sizeof(prime));
	sieve(B, prime);
	for(i = A+(1-(A&1)); i <= B-(1-(B&1)); i += 2)
	{
		if(prime[i])
		{
			t = i ;
			while(t != 0)
			{
				freq[t%10]++ ;
				t /= 10 ;
			}
		}
	}
	for(i = 1; i < 10; i++)
	{
		if(freq[i] > freq[f])
			f = i ;
	}
	printf("%lld %lld", f, freq[f]);
}
bool isprime(long long x)
{
	switch(x)
	{
		case 1 : 
			return false ;
			break ;
		case 2 :
		case 3 :
			return true ;
			break ;
		default : 
			if((x % 2 == 0) || (x % 3 == 0))
				return false ;
			int i ;
			for(i = 5; i*i <= x; i += 6)
			{
				if((x % i == 0) || (x % (i+2) == 0))
					return false ;
			}
			return true ;
	}
}
void sieve(long long x, bool p[])
{
	int i, j ;
	for(i = 2; i*i <= x; i++)
	{
		if(p[i])
		{
			for(j = i*i; j <= x; j += i)
				p[j] = false ;
		}
	}
}
