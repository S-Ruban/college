#include <stdio.h>
int main()
{
	int N, max, cur, a ;
	scanf("%d", &N);
	scanf("%d", &a);
	max = a ;
	cur = a ;
	N-- ;
	while(N--)
	{
		scanf("%d", &a);
		if(a > cur+a)
			cur = a ;
		else
			cur = cur + a ;
		if(max < cur)
			max = cur ;
	}
	printf("%d", max);
}
