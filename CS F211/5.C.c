#include <stdio.h>
int main()
{
	char N1[200], N2[200];
	scanf("%s %s", N1, N2);
	int i = 0, j = 0 ;
	while((N1[i] != '\0') || (N2[j] != '\0'))
	{
		if(N1[i] > N2[j])
			printf("%c", N1[i++]);
		else
			printf("%c", N2[j++]);
	}
}
