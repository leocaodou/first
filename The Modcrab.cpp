#include "stdio.h""
int main()
{
	int h1,a1,c1,h2,a2;
	scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
	int i=0,j,k=0,l=0,x,y,z;
	if(a2 > h1)
	{
		h1 = h1 + c1;
		i = i + 1;
		k = 1;
	}
	x = h2 / a1 + 1;
	y = (h1 - a2) / a2 + 1;
	z = x / y;
	i = i + z + x;
	printf("%d\n",i);
	for(j=1;j<=i;j++)
	{
		if(j==1 && k==1)
		{
			printf("HEAL\n");
			l++;
			continue;
		}
		if((j-l)%y==0)
		{
			printf("HEAL\n");
			l++;
		}
		else
			printf("STRIKE\n");
	}
	return 0;
}
