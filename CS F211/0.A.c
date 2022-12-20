#include <stdio.h>
int main()
{
	char A[1002], B[1002], C[1002];
	char tmp, carry = '0' ;
	int i, la, lb, lc ;
	for(i = 0; i < 1002; i++)
	{
		A[i] = '0' ;
		B[i] = '0' ;
		C[i] = '0' ;
	}
	scanf("%s", A);
	scanf("%s", B);
	for(i = 0; i < 1002; i++)
	{
		if((A[i] < '0') || (A[i] > '9'))
		{
			la = i ;
			A[i] = '0' ;
		}
		if((B[i] < '0') || (B[i] > '9'))
		{
			lb = i ;
			B[i] = '0' ;
		}
	}
	for(i = la-1; i >= 0; i--)
	{
		A[i+1002-la] = A[i];
		A[i] = '0' ;
	}
	for(i = lb-1; i >= 0; i--)
	{
		B[i+1002-lb] = B[i];
		B[i] = '0' ;
	}
	for(i = 1001; i >= 0; i--)
	{
		C[i] = (char)((int)((A[i]-48)+(B[i]-48)+(carry-48))%10 + 48);
		carry = (char)((int)((A[i]-48)+(B[i]-48)+(carry-48))/10 + 48);
	}
	for(i = 1001; i >= 0; i--)
	{
		if(C[i] != '0')
			lc = 1002-i ;
	}
	if(lc == 0)
		printf("0");
	else
	{
		for(i = 1002-lc; i < 1002; i++)
			printf("%c", C[i]);
	}
}
