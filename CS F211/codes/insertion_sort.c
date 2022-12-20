#include <stdio.h>
void sort(int arr[], int l, int r);
int main()
{
	
}
void sort(int arr[], int l, int r)
{
	int i, j, k ;
	for(i = l+1; i <= r; i++)
	{
		k = arr[i];
		j = i - 1 ;
		while((j >= l) && (arr[j] > k))
		{
			arr[j+1] = arr[j--];
		}
		arr[j+1] = k ;
	}
}
