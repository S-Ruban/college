#include <stdio.h>
#include <stdbool.h>
void swap(int *x, int *y);
void sort(int arr[], int l, int r);
int main()
{
	
}
void sort(int arr[], int l, int r)
{
	int i, j ;
	bool s ;
	for(i = l; i < r; i++)
	{
		s = false ;
		for(j = l; j < r-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				s = true ;
			}				
		}
		if(s)
			break ;
	}
}
void swap(int *x, int *y)
{
	*x += *y ;
	*y = *x - *y ;
	*x -= *y ;
}
