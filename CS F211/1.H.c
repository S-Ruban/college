#include <stdio.h>
int main()
{
	int N, i, cd = 0 ;
	scanf("%d", &N);
	int A[N];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	if(N&1)
	{
		int max = 0, min = 0, j, temp, tc ;
		for(j = 0; j < N; j++)
		{
			if(j&1)
				max -= (A[j]*A[j]*A[j]);
			else
				max += (A[j]*A[j]);
		}
		min = max ;
		for(i = 1; i < N; i++)
		{
			tc = 0 ;
			temp = A[N-1];
			for(j = N-1; j > 0; j--)
				A[j] = A[j-1];
			A[0] = temp ;
			for(j = 0; j < N; j++)
			{
				if(j&1)
					tc -= (A[j]*A[j]*A[j]);
				else
					tc += (A[j]*A[j]);
			}
			if(tc > max)
				max = tc ;
			if(tc < min)
				min = tc ;
		}
		cd = max - min ;
	}
	else
	{
		for(i = 0; i < N; i++)
		{
			if(i&1)
				cd -= ((A[i]*A[i])*(1+A[i]));
			else
				cd += ((A[i]*A[i])*(1+A[i]));
		}
	}
	if(cd < 0)
		cd *= -1 ;
	printf("%d", cd);
}
