#include<stdio.h>
int main()
{
	while(1)
	{
		int x,y,xi,xa,ya,yi;
		scanf("%d%d",&x,&y);
		if(x==0&&y==0)
			break;
		xa=x;
		xi=x;
		ya=y;
		yi=y;
		while(1)
		{
			scanf("%d%d",&x,&y);
			if(x==0&&y==0)
				break;
			if(x>xa)
				xa=x;
			if(x<xi)
				xi=x;
			if(y>ya)
				ya=y;
			if(y<yi)
				yi=y;
		}
		printf("%d %d %d %d\n",xi,yi,xa,ya);
	}
	return 0;
}
