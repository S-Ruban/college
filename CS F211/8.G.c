#include <stdio.h>
#include <stdbool.h>
void swap(int *x, int *y);
int main()
{
	int N, i, x ;
	char str[12];
	bool flag = true ;
	scanf("%d", &N);
	int q1[N], q2[N], e1 = 0, e2 = 0, f1 = 0, f2 = 0 ;
	scanf("%d");
	while(N--)
	{
		fgets(str, 11, stdin);
		switch(str[1])
		{
			case 'O' :
				if(flag)
				{
					while(f1-e1 != 1)
					{
						q2[e2++] = q1[f1++];
					}
					f1++ ;
				}
				else
				{
					while(f2-e2 != 1)
					{
						q1[e1++] = q2[f2++];
					}
					f2++ ;
				}
				flag = !flag ;
				break ;
			case 'R' :
				if(flag)
				{
					while(f1-e1 != 1)
					{
						q2[e2++] = q1[f1++];
					}
					x = q1[f1++];
					q2[e2++] = x ;
				}
				else
				{
					while(f2-e2 != 1)
					{
						q1[e1++] = q2[f2++];
					}
					x = q2[f2++];
					q1[e1++] = x ;
				}
				printf("%d\n", x);
				flag = !flag ;
				break ;
			default :
				x ^= x ;
				i = 5 ;
				while(str[i] != '\0')
				{
					x = x*10 + (int)(str[i++]-48);
				}
				x = (x+38)/10 ;
				if(flag)
					q1[e1++] = x ;
				else
					q2[e2++] = x ;
		}
	}
}
void swap(int *x, int *y)
{
    int t = *x ;
    *x = *y ;
    *y = t ;
}
