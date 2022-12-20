#include <stdio.h>
#include <stdlib.h>
int T, k, i ;
struct tasks
{
	int index ;
	int time ;
	int priority ;
} ;
int compare(struct tasks *t, int x, int y);
void heapify(struct tasks *t, int size, int i);
void sort(struct tasks *t);
int main()
{
	scanf("%d %d", &T, &k);
	struct tasks *t = (struct tasks*)malloc(T*sizeof(int)*sizeof(struct tasks)) ;
	for(i = 0; i < T; i++)
	{
		t[i].index = i ;
		scanf("%d %d", &t[i].time, &t[i].priority);
	}
	for(i = T/2 - 1; i >= 0; i--)
		heapify(t, T, i);
	sort(t);
	for(i = T-1; i > T-k; i--)
		printf("%d ", t[i].index);
	printf("%d", t[i].index);
	return 0 ;
}
int compare(struct tasks *t, int x, int y)
{
	if(t[x].priority < t[y].priority)
		return 1;
	else if((t[x].priority == t[y].priority) && (t[x].time < t[y].time)) 
		return 1;
	else if((t[x].priority == t[y].priority) && (t[x].time == t[y].time) && (t[x].index < t[y].index))
		return 1 ;
	return 0;
}
void heapify(struct tasks *t, int size, int i)
{
	int j ;
	if((2*i+1 < size) && (compare(t, 2*i+1, i)))
		j = 2*i+1 ;
	else 
		j = i;
	if((2*i+2 < size) && (compare(t, 2*i+2, j)))
		j = 2*i+2 ;
	if(j != i)
	{
		struct tasks temp ;
		temp = t[i];
		t[i] = t[j];
		t[j] = temp;
		heapify(t, size, j);
	}
}
void sort(struct tasks *t)
{
	int i ;
	for(i = 0; i < T; i++)
	{
		struct tasks temp;
		temp = t[0];
		t[0] = t[T-i-1];
		t[T-i-1] = temp;
		heapify(t, T-i-1, 0);
	}
}
