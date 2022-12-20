#include <stdio.h>
#include <stdlib.h>	// header file to use malloc for dynamic memory allocation
struct node
{
	int data ;			// data that the node stores
	struct node *next ;	// pointer of the node that points to the next node in the linkedlist
	struct node *prev ;	// pointer of the node that points to the previous node in the linkedlist
};
struct node *B  = NULL ;	// B stores the contents of the register
void print();	// function to print the contents of the register
void push_front(char x);	// function to push a bit at the MSB of the register
void push_rear(char x);		// function to push a bit at the LSB of the register
char pop_front();	// function to pop MSB of the register
char pop_rear();	// function to pop LSB of the register
void LR();	// function to rotate the register towards the left by one bit
void RR();	// function to rotate the register towards the right by one bit
void LS();	// function to shift the register towards the left by one bit
void RS();	// function to shift the register towards the right by one bit
void INC();	// function to increment the register by 1
void DEC();	// function to decrease the register by 1
int main()
{
	char b ;	// character variable to input a bit
	char q[3];	// character array to input the query
	scanf("%c", &b);
	while(b != '\n')
	{
		push_rear(b);
		scanf("%c", &b);
	}
	int T ;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", q);
		switch(q[0])
		{
			case 'L' :
				switch(q[1])
				{
					case 'R' :
						LR();
						break ;
					default :
						LS();
				}
				break ;
			case 'R' :
				switch(q[1])
				{
					case 'R' :
						RR();
						break ;
					default :
						RS();
				}
				break ;
			case 'I' :
				INC();
				break ;
			default :
				DEC();
				break ;
		}
	}
	print();
}
void print()
{
	struct node *ptr = B ;	// defining a pointer that points to the start of the node
	while(ptr != NULL)
	{
		printf("%c", ptr->data);
		ptr = ptr->next ;
	}
}
void push_front(char x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));	// defining a 
	ptr->data = x ;
	if(B == NULL)
	{
		ptr->next = NULL ;
		ptr->prev = NULL ;
	}
	else
	{
		ptr->prev = NULL ;
		ptr->next = B ;
		B->prev = ptr ;
	}
	B = ptr ;
}
void push_rear(char x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = x ;
	if(B == NULL)
	{
		ptr->next = NULL ;
		ptr->prev = NULL ;
		B = ptr ;
	}
	else
	{
		struct node *last = B ;
		while(last->next != NULL)	// finding the last node
		{
			last = last->next ;
		}
		last->next = ptr ;
		ptr->prev = last ;
		ptr->next = NULL ;
	}
}
char pop_front()
{
	if(B->next == NULL)
		return B->data ;
	struct node *ptr = B ;
	B = B->next ;
	B->prev = NULL ;
	char ch = ptr->data ;
	free(ptr);	// deleting the first node
	return ch ;
}
char pop_rear()
{
	if(B->next == NULL)
		return B->data ;
	struct node *ptr = B ;
	while(ptr->next != NULL)
	{
		ptr = ptr->next ;	// traversing to the last node
	}
	char ch = ptr->data ;
	(ptr->prev)->next = NULL ;
	free(ptr);
	return ch ;
}
void LR()	// left rotate is done by popping the first element and pushing it to the rear
{
	if(B->next == NULL)	// handling the case where there is only 1 bit
		return ;
	char b = pop_front();
	push_rear(b);
}
void RR()	// right rotate is done by popping the last element and pushing it to the front
{
	if(B->next == NULL)	// handling the case where there is only 1 bit
		return ;
	char b = pop_rear();
	push_front(b);
}
void LS()	// left shift is done by popping the first element and pushing 0 to the rear
{
	if(B->next == NULL)	// handling the case where there is only 1 bit
		return ;
	pop_front();
	push_rear('0');
}
void RS()	// right shift is done by popping the last element and pushing 0 to the front
{
	if(B->next == NULL)	// handling the case where there is only 1 bit
		return ;
	pop_rear();
	push_front('0');
}
void INC()
{
	if(B->next == NULL)
		B->data = (char)((((int)B->data-48)^1)+48);	// handling the case where there is only 1 bit
	else
	{
		struct node *ptr = B ;
		char carry = '1', a, b ;	// defining initial carry as 1, to increment
		while(ptr->next != NULL)
		{
			ptr = ptr->next ;	// traversing to the last node
		}
		while(ptr != NULL)
		{
			a = ptr->data ;
			b = carry ;
			carry = (char)((((int)a-48)&(int)(b-48))+48);
			ptr->data = (char)((((int)a-48)^(int)(b-48))+48);
			ptr = ptr->prev ;
		}
	}
}
void DEC()
{
	if(B->next == NULL)
		B->data = (char)((((int)B->data-48)^1)+48);	// handling the case where there is only 1 bit
	else
	{
		struct node *ptr = B ;
		while(ptr->next != NULL)
		{
			ptr = ptr->next ;	// traversing to the last node
		}
		while(ptr != NULL)
		{
			if((((int)ptr->data)-48)&1)
			{
				ptr->data = (char)((((int)ptr->data-48)^1)+48);	// flipping all bits
				return ;
			}
			else
			{
				ptr->data = (char)((((int)ptr->data-48)^1)+48);	// flipping all bits
				ptr = ptr->prev ;
			}
		}
	}
}
