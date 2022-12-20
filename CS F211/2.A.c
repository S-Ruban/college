#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int f(int x);
bool isprime(int x);
int main()
{
	int N ;
	scanf("%d", &N);
	printf("%d", f(N));
}
int f(int x)
{
	if(isprime(x))
	{
		//printf("f(%d) = f(%d)\n", x, x);
		return x ;
	}
	if(((int)sqrt(x))*((int)sqrt(x)) == x)
	{
		if(isprime((int)sqrt(x)))
		{
			//printf("f(%d) = f(%d)\n", x, (int)sqrt(x));
			return x ;
		}
	}
	int y, z ;
	for(z = 2; z <= x; z++)
	{
		if(x % z == 0)
			break ;
	}
	y = z++ ;
	for(; z <= x; z++)
	{
		if(x % z == 0)
			break ;
	}
	//printf("f(%d) = f(%d) + f(%d)\n", x, x/y, x/z);
	return f(x/y)+f(x/z);
}
bool isprime(int x)
{
	switch(x)
	{
		case 1 : 
		case 2 :
		case 3 :
			return true ;
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
