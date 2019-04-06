#include <stdio.h>
int main()
{
	int n,s,i;
	scanf("%d%d",&n,&s);
	int a[n],b[n],x = 0,y = 0,z =0;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0;i < n;i++)
	{
		scanf("%d",&b[i]);
	}
	if(a[s-1] == 0)
	{
		x = 1;
		if(b[s - 1] == 1)
		{
			for(i = s-1;i <n;i++)
			{
				if(a[i] == 1 && b[i] == 1)
				{
					z=1;
					break;
				}
			}
			if(z != 1)
				z = 2;
		}
	}
	if(b[s-1] == 0)
	{
		y = 1;
	}
	if((x == 1 && y == 1) || a[0] == 0 || (a[n-1] == 0 &&s ==n) || z ==2)
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES");
		return 0;
	}
}