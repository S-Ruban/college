#include <stdio.h>
int main()
{
	int N, i ;
	scanf("%d", &N);
	int f[N/2+1];
	f[0] = 1 ;
	for(i = 1; i <= N/2; i++)
		f[i] = f[i-1] + f[i/2];
	printf("%d", f[N/2]);
}
