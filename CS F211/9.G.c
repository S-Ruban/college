#include <stdio.h>
int main()
{
	int N, S, i, t, p ;
	char d ;
	scanf("%d %d", &N, &S);
	if(N == 0)
	{
		printf("0");
		return 0 ;
	}
	scanf("%d %c", &p, &d);
	if(d == 'L')
		t = p ;
	else
		t = S-p ;
	for(i = 1; i < N; i++)
	{
		scanf("%d %c", &p, &d);
		if(d == 'L')
		{
			if(p > t)
				t = p ;
		}
		else
		{
			if(S-p > t)
				t = S-p ;
		}
	}
	printf("%d", t);
}
