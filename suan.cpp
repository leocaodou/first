#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
class node
{
public:
	int val = -1;
	node* next = NULL; 
};
int main()
{
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	int a[100000] = {0};
	node h[100000];
	for(int i =0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i =0;i < m;i++)
	{
		int y;
		cin >> y;
		int k = y % 100000;
		if(h[k].val != -1)
		{
			node* q = &h[k];
			while(q->next != NULL)
				q = q->next;
			q->next = new node();
			q = q->next;
			q->val = y;
		}
		else
			h[k].val = y;
	}
	for(int i = 0;i < n;i++)
	{
		int y,k;
		y = x - a[i];
		if(y < 0)
			continue;
		k = y % 100000;
		if(h[k].val == y)
		{
			printf("YES");
			return 0;
		}
		if(h[k].val == -1) 
			continue;
		node* q = &h[k];
		while(q->next != NULL)
		{
			q = q->next;
			if(q->val == y)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}
