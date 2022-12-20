#include <stdio.h>
int max(int x, int y);
int main()
{
	int N, i, a[100001], stack[100001], top = -1, ma ;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= N; i++)
	{
		while (top >= 0 && a[i] <= a[stack[top]])
		{
			if (!top)
				ma = max(ma, a[stack[top]]*(i-1));
			else
				ma = max(ma, a[stack[top]]*(i-stack[top-1]-1));
			top-- ;
		}
		stack[++top] = i ;
	}
	while (top != -1)
	{
		if (!top)
			ma = max(ma, a[stack[top]]*N);
		else
			ma = max(ma, a[stack[top]]*(N-stack[top-1]));
		top-- ;
	} 
	printf("%d", ma);
}
int max(int x, int y)
{
	if(x > y)
		return x ;
	return y ;
}
