#include<stdio.h>
#include<math.h>
int main()
{
	while(1)
	{
		int a,x,y,p,n=0,i,j;
		scanf("%d",&a);
		if(a==0)
			break;
		for(i=2;i<a/2;i++)
		{
			x=1;
			y=1;
			for(j=2;j<=sqrt(i);j++)
			{
				if(i%j==0)
				{
					x=0;
					break;
				}
			}
			if(x==0)
				continue;
			else
			{
				p=a-i;
				for(j=2;j<=sqrt(p);j++)
				{
					if(p%j==0)
					{
						y=0;
						break;
					}
				}
			}
			if(x==1&&y==1)
				n++;		
		}
		printf("%d\n",n);
	}
	return 0;
}
