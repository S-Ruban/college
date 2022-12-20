#include <stdio.h>
#include <stdbool.h>
int main()
{
	int N, i, t = 1, li, ri, L = 0, R = 0, d ;
	bool fl, fr ;
	scanf("%d", &N);
	int A[N];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	i = 0 ;
	L = A[0];
	R = A[0];
	while(t < N)
	{
		//printf("t : %d\n", t);
		li = t ;
		ri = 2*li ;
		fl = false ;
		fr = false ;
		while(!fl||!fr)
		{
			if(!fl)
			{
				if(A[li] != -1)
				{
					fl = true ;
					L += A[li];
					//printf("L : %d ", li);
				}
			}
			if(!fr)
			{
				if(A[ri] != -1)
				{
					fr = true ;
					R += A[ri];
					//printf("R : %d ", ri);
				}
			}
			li += (int)(!fl);
			ri -= (int)(!fr);
		}
		t = 2*t+1 ;
		/*printf("L : %d ", A[li]);
		printf("R : %d ", A[ri]);
		printf("\n");*/
	}
	d = L - R ;
	if(d < 0)
		d *= -1 ;
	printf("%d",d);
}
