#include <stdio.h>
int parity(int x);
int main()
{
	int N, i, j, x ;
	int par[1024];
	for(i = 0; i < 1024; i++)
		par[i] = 0 ;
	char str[17];
	scanf("%d", &N);
	scanf("%d");
	while(N--)
	{
		fgets(str, 16, stdin);
		x = 0 ;
		j = 0 ;
		while(str[j] != '\0')
		{
			if((str[j] >= '0') && (str[j] <= '9'))
				x = x*10 + (int)(str[j]-48);
			j++ ;
		}
		switch(str[0])
		{
			case 'q' :
				printf("%d\n", par[parity(x)]);
				break ;
			default :
				par[parity(x)] += (2*(((int)str[0])&1)-1);
		}
	}
}
int parity(int x)
{
	int p = 0, d = 1000000000 ;
	while(d > 0)
	{
		p = p*2 + ((x/d)&1);
		d /= 10 ; 
	}
	return p ;
}
