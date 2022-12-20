#include <stdio.h>
#include <stdbool.h>
char ch ;
int N, p = 0, pos ;
bool flag = false, e = false, b0 = false, b1 = false, b2 = false, b3 = false ;
void recur();
int main()
{
	scanf("%d\n", &N);
	recur();
	if(!e)
		printf("NO");
}
void recur()
{
	scanf("%c", &ch);
	if(ch == '\n')
		return ;
	if(((int)ch)&1)
	{
		if(flag)
		{
			if(b1)
			{
				if(b2)
				{
					flag = false ;
					b0 = false ;
					b1 = false ;
					b2 = false ;
					b3 = false ;
				}
				else
					b2 = true ;
			}
			else
				b1 = true ;
		}	
	}
	else
	{
		if(flag)
		{
			if((!b0) && b1 && b2 && (!b3))
			{
				if(!e)
				{
					e = true ;
					printf("YES");
				}
				printf(" %d", pos);
				flag = true ;
				pos = p+1 ;
			}
			else
				flag = false ;
			b1 = false ;
			b2 = false ;
			b3 = false ;
		}
		else
		{
			flag = true ;
			pos = p+1 ;
		}
		b0 = false ;
	}
	p++ ;
	recur();
}
