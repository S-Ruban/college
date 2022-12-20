#include <stdio.h>
int main()
{
	int N, i, t = -1 ;
	scanf("%d", &N);
	int a[N], stack[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		while((t >= 0) && (a[stack[t]-1] >= a[i]))
		{
			t-- ;
		}
		if(t == -1)
			printf("-1 ");
		else
			printf("%d ", stack[t]);
		stack[++t] = i+1 ;
	}
}
