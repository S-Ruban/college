#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    bool isLeaf ;
    struct node* character[26];
};
void insert(struct node *head, char* str);
bool search(struct node* head, char* str);
int main()
{
    int T, N, i, j ;
	bool flag ;
	char t ;
	char player[2][6] = {"Bob\0", "Alice\0"};
	char tmp[10];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		char words[N][10];
		struct node* trie = (struct node*)malloc(sizeof(struct node));
	    trie->isLeaf = false ;
    	for (i = 0; i < 26; i++)
        	trie->character[i] = NULL;
		for(i = 0; i < N; i++)
		{
			flag = true ;
			scanf("%s", words[i]);
			if(i > 0)
			{
				flag = true ;
				j = 0 ;
				while(words[i-1][j] != '\0')
				{
					t = words[i-1][j++];
				}
				if(t != words[i][0])
				{
					printf("%s ", player[i&1]);
					flag = false ;
				}
				else
				{
					if(search(trie, words[i]))
					{
						printf("%s ", player[i&1], i);
						flag = false ;
					}
					else
						insert(trie, words[i]);			
				}
			}
			else
				insert(trie, words[i]);
			if(!flag)
				break ;
		}
		if(flag)
			printf("%s ", player[i&1]);
		if(i != N-1)
			scanf("%s", tmp);
	}
}
void insert(struct node *head, char* str)
{
    struct node* curr = head ;
    int i ;
    while (*str)
    {
        if (curr->character[*str-'a'] == NULL)
		{
            curr->character[*str-'a'] = (struct node*)malloc(sizeof(struct node));
		    curr->character[*str-'a']->isLeaf = false ;
		    for (i = 0; i < 26; i++)
		        curr->character[*str-'a']->character[i] = NULL ;
        }
        curr = curr->character[*str-'a'];
        str++;
    }
    curr->isLeaf = true ;
}
bool search(struct node* head, char* str)
{
    if (head == NULL)
        return false ;
    struct node* curr = head;
    while (*str)
    {
        curr = curr->character[*str - 'a'];
        if (curr == NULL)
            return false ;
        str++;
    }
    return curr->isLeaf ;
}
