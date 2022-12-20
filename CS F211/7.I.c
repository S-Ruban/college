#include <stdio.h>
int main()
{
	int N, L, i, j, m ;
	scanf("%d %d", &N, &L);
	int x[N], s[N], A[N], max[N];
	for(i = 0; i < N; i++)
		scanf("%d", &x[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &s[i]);
	A[0] = s[0];
	m = s[0];
	max[0] = s[0];
	for(i = 1; i < N; i++)
	{
		if(x[i-1]-x[i] > L)
			A[i] = A[i-1]+s[i];
		else
		{
			m = 0 ;
			for(j = 0; x[i]-x[j] > L; j++)
			{
				if(m < A[j])
					m = A[j];
			}
			A[i] = m + s[i];
		}
		if(A[i] > max[i-1])
			max[i] = A[i];
		else
			max[i] = max[i-1];
	}
	printf("%d", max[N-1]);
}
