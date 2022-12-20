#include <stdio.h>
int main()
{
	long long N, i, j, f = 0, t = 0, X = 0, m = 1 ;
	scanf("%lld\n", &N);
	char cmd[N][32];
	long long stk[4999];
	for(i = 0; i < 4999; i++)
		stk[i] = 0 ;
	for(i = 0; i < N; i++)
	{
		scanf("%[^\n]%*c", &cmd[i]);
		j = ((int)cmd[i][0]-61)/3 ;
		switch(cmd[i][0])
		{
			case 'F' :
				t = 0 ;
				if(cmd[i][j] == '-')
					j++ ;
				while(cmd[i][j] != '\0')
				{
					t = t*10 + (long long)(cmd[i][j++]-48);
				}
				if(cmd[i][3] == '-')
					t *= -1 ;
				t *= m;
				X += t ;
				break ;
			case 'L' :
				while(cmd[i][j] != '\0')
				{
					stk[f] = stk[f]*10 + (long long)(cmd[i][j++]-48);
				}
				m *= stk[f++] ;
				break ;
			default :
				m /= stk[--f];
		}
	}
	printf("%lld", X);
}
