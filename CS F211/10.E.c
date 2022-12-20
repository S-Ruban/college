#include <stdio.h>
#define MAX(x,y) ((x>y)?x:y)
int main()
{
	int N, i, j, p = 0, cur ;
	scanf("%d", &N);
	int a[N], b[N], c[N];
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &b[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &c[i]);
	if((a[0] > b[0]) && (a[0] > c[0]))
	{
		p += a[0];
		cur = 0 ;
	}
	else if((b[0] > a[0]) && (b[0] > c[0]))
	{
		p += b[0];
		cur = 1 ;
	}
	else
	{
		p += c[0];
		cur = 2 ;
	}
	for(i = 1; i < N; i++)
	{
		switch(cur)
		{
			case 0 :
				if(b[i] > c[i])
				{
					p += b[i];
					cur = 1 ;
				}
				else
				{
					p += c[i];
					cur = 2 ;
				}
				break ;
			case 1 :
				if(a[i] > c[i])
				{
					p += a[i];
					cur = 0 ;
				}
				else
				{
					p += c[i];
					cur = 2 ;
				}
				break ;
			default :
				if(a[i] > b[i])
				{
					p += a[i];
					cur = 0 ;
				}
				else
				{
					p += b[i];
					cur = 1 ;
				}
		}
	}
	printf("%d", p);
}
