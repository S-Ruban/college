#include <stdio.h>
void swap(int *x, int *y);
void heapify(int arr[], int s, int i);
void sort(int arr[], int s);
int main()
{
	int i, n ;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}
void swap(int *x, int *y)
{
	*x = *x + *y ;
	*y = *x - *y ;
	*x = *x - *y ;
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
        swap(&arr[i], &arr[largest]);
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
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
