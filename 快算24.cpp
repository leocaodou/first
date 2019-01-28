#include<stdio.h>
int main()
{
	double a[5],s;
	int i,j,k;
	char b[5];
	b[1]='+';b[2]='-';b[3]='*';b[4]='/';
	for(i=1;i<=4;i++)
	{
		scanf("%lf",&a[i]);
	}
	s=a[1];
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			for(k=1;k<=4;k++)
			{
				switch(i)
				{
					case 1:s=s+a[2];break;
					case 2:s=s-a[2];break;
					case 3:s=s*a[2];break;
					case 4:s=s/a[2];break;
				}
				switch(j)
				{
					case 1:s=s+a[3];break;
					case 2:s=s-a[3];break;
					case 3:s=s*a[3];break;
					case 4:s=s/a[3];break;
				}
				switch(k)
				{
					case 1:s=s+a[4];break;
					case 2:s=s-a[4];break;
					case 3:s=s*a[4];break;
					case 4:s=s/a[4];break;
				}
				if(s==24)
				{
					printf("%d%c%d%c%d%c%d",a[1],b[i],a[2],b[j],a[3],b[k],a[4]);
					return 0;
				}
				else
					s=a[1];
			}
		}
	}
	s=a[2];
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			for(k=1;k<=4;k++)
			{
				switch(i)
				{
					case 1:s=s+a[3];break;
					case 2:s=s-a[3];break;
					case 3:s=s*a[3];break;
					case 4:s=s/a[3];break;
				}
				switch(j)
				{
					case 1:s=s+a[4];break;
					case 2:s=s-a[4];break;
					case 3:s=s*a[4];break;
					case 4:s=s/a[4];break;
				}
				switch(k)
				{
					case 1:s=s+a[1];break;
					case 2:s=a[1]-s;break;
					case 3:s=s*a[1];break;
					case 4:s=a[1]/s;break;
				}
				if(s==24)
				{
					printf("%d%c((%d%c%d)%c%d)",a[1],b[k],a[2],b[i],a[3],b[j],a[4]);
					return 0;
				}
				else
					s=a[2];
			}
		}
	}
	s=a[2];
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			for(k=1;k<=4;k++)
			{
				switch(i)
				{
					case 1:s=s+a[3];break;
					case 2:s=s-a[3];break;
					case 3:s=s*a[3];break;
					case 4:s=s/a[3];break;
				}
				switch(j)
				{
					case 1:s=s+a[1];break;
					case 2:s=a[1]-s;break;
					case 3:s=s*a[1];break;
					case 4:s=a[1]/s;break;
				}
				switch(k)
				{
					case 1:s=s+a[4];break;
					case 2:s=s-a[4];break;
					case 3:s=s*a[4];break;
					case 4:s=s/a[4];break;
				}
				if(s==24)
				{
					printf("%d%c(%d%c%d)%c%d",a[1],b[j],a[2],b[i],a[3],b[k],a[4]);
					return 0;
				}
				else
					s=a[2];
			}
		}
	}
	s=a[3];
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			for(k=1;k<=4;k++)
			{
				switch(i)
				{
					case 1:s=s+a[4];break;
					case 2:s=s-a[4];break;
					case 3:s=s*a[4];break;
					case 4:s=s/a[4];break;
				}
				switch(j)
				{
					case 1:s=s+a[2];break;
					case 2:s=a[2]-s;break;
					case 3:s=s*a[2];break;
					case 4:s=a[2]/s;break;
				}
				switch(k)
				{
					case 1:s=s+a[1];break;
					case 2:s=a[1]-s;break;
					case 3:s=s*a[1];break;
					case 4:s=a[1]/s;break;
				}
				if(s==24)
				{
					printf("%.0lf%c(%.0lf%c(%.0lf%c%.0lf))",a[1],b[k],a[2],b[j],a[3],b[i],a[4]);
					return 0;
				}	
				else
					s=a[3];	
			}
		}
	}
}
