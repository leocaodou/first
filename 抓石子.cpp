#include <stdio.h> 
int c[76923078][3];
int main()
{
	int a[4][3],b[4],i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=2;j++)
		scanf("%d",&a[i][j]);
	}
	c[0][1]=-1;
	c[0][2]=-1;
	for(i=1;i<=76923078;i=i+13)
	{
		
		c[i][1]=c[i-1][1]+3;
		c[i+1][1]=c[i][1]+3;
		c[i+2][1]=c[i+1][1]+2;
		c[i+3][1]=c[i+2][1]+3;
		c[i+4][1]=c[i+3][1]+3;
		c[i+5][1]=c[i+4][1]+2;
		c[i+6][1]=c[i+5][1]+3;
		c[i+7][1]=c[i+6][1]+2;
		c[i][2]=c[i-1][2]+2;
		c[i+1][2]=c[i][2]+2;
		c[i+2][2]=c[i+1][2]+1;
		c[i+3][2]=c[i+2][2]+2;
		c[i+4][2]=c[i+3][2]+2;
		c[i+5][2]=c[i+4][2]+1;
		c[i+6][2]=c[i+5][2]+2;
		c[i+7][2]=c[i+6][2]+1;
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=76923078;j++)
		{
			if((a[i][1]==c[j][1]&&a[i][2]==c[j][2])||(a[i][2]==c[j][1]&&a[i][1]==c[j][2]))
			{
				b[i]=0;
				break;
			}
			else
				b[i]=1;
		} 
	}
	for(i=1;i<=3;i++)
	printf("%d\n",b[i]);
	return 0;	
}
