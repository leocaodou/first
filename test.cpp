#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
using namespace std;
#define CSZL 10 
#define FPZL 10 
typedef struct hanoi 
{ 
	int n; 
	char x,y,z; 
}hanoi;
typedef struct Stack 
{ 
	hanoi *base,*top; 
	int stacksize; 
}Stack;
int InitStack(Stack *S)
{
	S->base=(hanoi *)malloc(CSZL*sizeof(hanoi)); 
	S->top=S->base; 
	S->stacksize=CSZL; 
	return 1; 
} 
int PushStack(Stack *S,int n,char x,char y,char z) 
{ 
	S->top->n=n;  
	S->top->x=x; 
	S->top->y=y; 
	S->top->z=z; 
	S->top++; 
	return 1; 
} 
int PopStack(Stack *S,int *n,char *x,char *y,char *z) 
{ 
	if(S->top==S->base) 
		return 0; 
	else 
	{ 
		S->top--;
		*n=S->top->n;
		*x=S->top->x;
		*y=S->top->y; 
		*z=S->top->z; 
		return 1; 
	} 
} 
bool EmptyStack(Stack *S) 
{
	if(S->base==S->top) 
		return 1;
	else 
		return 0;
}
int i=1;
void Move(char x,char z) 
{ 
	printf("\n\t\t第%d步从%c-->%c",i++,x,z);
} 
int main() 
{ 
	int n; 
	char x,y,z; 
	Stack *S; 
	S=(Stack *)malloc(sizeof(Stack)); 
	if(!InitStack(S))  
		return 0; 
	printf("请输入汉罗塔的初始盘子数量和名称：");
	cin >>n >> x >> y >> z;
	if(!PushStack(S,n,x,y,z)) 
		return 0; 
	while(!EmptyStack(S)) 
	{ 
		if(!PopStack(S,&n,&x,&y,&z)) 
			break; 
		if(n==1) 
		{
			Move(x,z); 
		} 
		else 
		{ 
			if(!PushStack(S,n-1,y,x,z)) 
				break; 
			if(!PushStack(S,1,x,y,z))
				break; 
			if(!PushStack(S,n-1,x,z,y))
				break; 
		} 
	} 
	free(S->base); 
	S->base=NULL; 
	S->top=NULL; 
	S->stacksize=0; 
	return 0; 
}
