#include <stdio.h>
void merge(int s, int arr[s][2], int l, int m, int r);
void sort(int s, int arr[s][2], int l, int r);
int main()
{
	int M, i, j, L = 0 ;
	int qp[4];
	for(i = 0; i < 4; i++)
		qp[i] = 0 ;
	scanf("%d", &M);
	int Q[M][2];
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &Q[i][0], &Q[i][1]);
		if(Q[i][0] >= 0)
		{
			if(Q[i][1] >= 0)
				qp[0]++ ;
			else
				qp[3]++ ;
		}
		else
		{
			if(Q[i][1] >= 0)
				qp[1]++ ;
			else
				qp[2]++ ;
		}
	}
	int Q1[qp[0]][2], Q2[qp[1]][2], Q3[qp[2]][2], Q4[qp[3]][2];
	for(i = 0; i < 4; i++)
		qp[i] = 0 ;
	for(i = 0; i < M; i++)
	{
		if(Q[i][0] >= 0)
		{
			if(Q[i][1] >= 0)
			{
				Q1[qp[0]][0] = Q[i][0];
				Q1[qp[0]++][1] = Q[i][1];
			}
			else
			{
				Q4[qp[3]][0] = Q[i][0];
				Q4[qp[3]++][1] = Q[i][1];
			}
		}
		else
		{
			if(Q[i][1] >= 0)
			{
				Q2[qp[1]][0] = Q[i][0];
				Q2[qp[1]++][1] = Q[i][1];
			}
			else
			{
				Q3[qp[2]][0] = Q[i][0];
				Q3[qp[2]++][1] = Q[i][1];
			}
		}
	}
	sort(qp[0], Q1, 0, qp[0]-1);
	sort(qp[1], Q2, 0, qp[1]-1);
	sort(qp[2], Q3, 0, qp[2]-1);
	sort(qp[3], Q4, 0, qp[3]-1);
	/*for(i = 0; i < qp[0]; i++)
		printf("%d %d\n", Q1[i][0], Q1[i][1]);
	for(i = 0; i < qp[1]; i++)
		printf("%d %d\n", Q2[i][0], Q2[i][1]);
	for(i = 0; i < qp[2]; i++)
		printf("%d %d\n", Q3[i][0], Q3[i][1]);
	for(i = 0; i < qp[3]; i++)
		printf("%d %d\n", Q4[i][0], Q4[i][1]);*/
	for(i = 0; i < qp[0]; i++)
	{
		Q[i][0] = Q1[i][0];
		Q[i][1] = Q1[i][1];
	}
	for(i = 0; i < qp[1]; i++)
	{
		Q[i+qp[0]][0] = Q2[i][0];
		Q[i+qp[0]][1] = Q2[i][1];
	}
	for(i = 0; i < qp[2]; i++)
	{
		Q[i+qp[0]+qp[1]][0] = Q3[i][0];
		Q[i+qp[0]+qp[1]][1] = Q3[i][1];
	}
	for(i = 0; i < qp[3]; i++)
	{
		Q[i+qp[0]+qp[1]+qp[2]][0] = Q4[i][0];
		Q[i+qp[0]+qp[1]+qp[2]][1] = Q4[i][1];
	}
	for(i = 0; i < M-1; i++)
		L += (abs(Q[i][0]-Q[i+1][0]) + abs(Q[i][1]-Q[i+1][1]));	
	L += (abs(Q[0][0]-Q[M-1][0]) + abs(Q[0][1]-Q[M-1][1]));
	printf("%d", L);
}
void merge(int s, int arr[s][2], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][2], a2[n2][2];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if((double)a1[i][1]/a1[i][0] < (double)a2[j][1]/a2[j][0])
		{
			arr[k][0] = a1[i][0];
			arr[k++][1] = a1[i++][1];
		}
		else
		{
			arr[k][0] = a2[j][0];
			arr[k++][1] = a2[j++][1];
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k++][1] = a1[i++][1];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k++][1] = a2[j++][1];
	}
}
void sort(int s, int arr[s][2], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
