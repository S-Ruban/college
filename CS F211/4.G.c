#include <stdio.h>
long long merge(long long arr[], long long temp[], long long l, long long m, long long r);	// merge function to count number of swaps while merging two sorted arrays
long long sort(long long arr[], long long temp[], long long l, long long r);	// sort function to count number of swaps while sorting an array
int main()
{
	long long N, i ;
	scanf("%lld", &N);
	long long a[N], temp[N];
	for(i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	printf("%lld", sort(a, temp, 0, N-1));
}
long long sort(long long arr[], long long temp[], long long l, long long r)
{
    if(l >= r)
    	return 0 ;	// below line returns number of swaps when sorting left hand side, right hand side, and when merging the sorted arrays
    return (sort(arr, temp, l, (l+r)/2)+sort(arr, temp, (l+r)/2 + 1, r)+merge(arr, temp, l, (l+r)/2 + 1, r));
}
long long merge(long long arr[], long long temp[], long long l, long long m, long long r)
{
    long long i = l, j = m, k = l, c = 0 ;
    while ((i <= m-1) && (j <= r))
	{
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            c += (m-i);		// (m-i) swaps to ensure arr[i] <= arr[j]
        }
    }
    while (i <= m-1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
    return c ;
}
