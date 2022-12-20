#include <stdio.h>
void heapify(int arr[], int s, int i);
void sort(int arr[], int s);
int search(int arr[], int l, int r, int k);
int temp ;
int main()
{
	int N, q, i, j, x ;
	scanf("%d", &N);
	int a[N];
	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	sort(a, N);
	while(q--)
	{
		scanf("%d", &x);
		if(search(a, 0, N-1, x) == -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
void heapify(int arr[], int s, int i)
{
    int l = 2*i+1, r = l+1, largest = i;
    if((l < s) && (arr[l] > arr[largest]))
        largest = l;
    if((r < s) && (arr[r] > arr[largest]))
        largest = r;
    if(largest != i)
	{
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp ;
        heapify(arr, s, largest);
    }
}
void sort(int arr[], int s)
{
	int i ;
    for(i = s/2 - 1; i >= 0; i--)
        heapify(arr, s, i);
    for(i = s - 1; i > 0; i--)
	{
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp ;
        heapify(arr, i, 0);
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
	return -1 ;
}
