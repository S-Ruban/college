#include <stdio.h>
void merge(int arr[], int l, int m, int r);
void sort(int arr[], int l, int r);
int search(int arr[], int l, int r, int k);
int find(int arr[], int k);
int N, M, L, U, V, A, B, K, i, j, x ;
int main()
{
	int P = 0 ;
	scanf("%d %d %d\n", &N, &M, &L);
	scanf("%d %d %d %d %d\n", &U, &V, &A, &B, &K);
	int T[M], C[L];
	for(i = 0; i < M; i++)
		scanf("%d", &T[i]);
	for(i = 0; i < L; i++)
		scanf("%d", &C[i]);
	sort(T, 0, M-1);
	sort(C, 0, L-1);
	for(i = search(T, 0, M-1, U); i < search(T, 0, M-1, V); i++)
	{
		if(A*C[L-1]+B < T[i+1]-T[i])
		{
			printf("NOT POSSIBLE");
			return -1 ;
		}
		x = (T[i+1]-T[i]-B)/A ;
		if((T[i+1]-T[i]-B) % A != 0)
			x++ ;
		if(T[i+1]-T[i]-B < 0)
			x = 0 ;
		//printf("%d %d %d %d\n", T[i+1]-T[i], x, find(C, x), C[find(C, x)]);
		//printf("%d ", C[find(C, x)]);
		P += (K*C[find(C, x)]);
	}
	printf("%d", P);
}
void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1], a2[n2];
	for(i = 0; i < n1; i++)
		a1[i] = arr[l+i];
	for(i = 0; i < n2; i++)
		a2[i] = arr[m+1+i];
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i] < a2[j])
			arr[k++] = a1[i++];
		else
			arr[k++] = a2[j++];
	}
	while(i < n1)
	{
		arr[k++] = a1[i++];
	}
	while(j < n2)
	{
		arr[k++] = a2[j++];
	}
}
void sort(int arr[], int l, int r)
{
	if(l < r)
	{
		sort(arr, l, (l+r)/2);
		sort(arr, (l+r)/2 + 1, r);
		merge(arr, l, (l+r)/2, r);
	}
}
int search(int arr[], int l, int r, int k)
{
	if(l <= r)
	{
		if(arr[(l+r)/2] == k)
			return (l+r)/2 ;
		else if(arr[(l+r)/2] > k)
			return search(arr, l, (l+r)/2 - 1, k);
		else
			return search(arr, (l+r)/2 + 1, r, k);
	}
}
int find(int arr[], int k)
{
	int l = 0, h = L-1, mid ;
    while (l <= h)
	{
        mid = (l+h)/2;
        if (arr[mid] == k)
            return mid ;
        else if (arr[mid] < k)
            l = mid+1 ;
        else
            h = mid-1 ;
    }
    return h+1 ;
}
