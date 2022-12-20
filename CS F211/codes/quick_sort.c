#include <stdio.h>
void swap(int *x, int *y);
void sort(int arr[], int l, int r);
int partition(int arr[], int p, int r);
int main()
{
	
}
int partition(int arr[], int l, int r)
{
	int p = arr[r], i = l-1, j ;
	for(j = l; j < r; j++)
	{
		if(arr[j] < p)
			swap(&arr[++i], &arr[j]);
	}
	swap(&arr[i+1], &arr[r]);
	return (i+1);
}
void sort(int arr[], int l, int r)
{
	if(l < r)
	{
		int q = partition(arr, l, r);
		sort(arr, l, q-1);
		sort(arr, q+1, r);
	}
}
void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp ; 
} 
