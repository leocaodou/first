#include<stdio.h>
struct stu
{
	int fen;
	int hao;
	char name[20];
	struct stu* next=NULL;
};
int main()
{
	struct stu a,b,c,d,*p,*head;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=NULL;
	p=head;
	while(p!=NULL)
	{
		scanf("%d%d%s",&p->fen,&p->hao,p->name);
		p=p->next;
	}
	p=head;
	a.next=&c;
	while(p!=NULL)
	{
		printf("%d\t%d\t%s\n",p->fen,p->hao,p->name);
		p=p->next;
	}
	return 0;
}
