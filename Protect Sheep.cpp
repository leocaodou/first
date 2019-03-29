#include <stdio.h>
int main()
{
	int r,c,i,j,k=0;
	scanf("%d%d",&r,&c);
	getchar();
	char a[r][c];
	int b[r*c][2];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]=getchar();
			if(a[i][j] == 'W')
			{
				b[k][0]=i;
				b[k][1]=j;
				k++;
			}
		}
		getchar();
	}
	if(k==0)
	{
		printf("Yes\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	for(i=0;i<k;i++)
	{
		if(a[b[i][0]+1][b[i][1]] == 'S' ||a[b[i][0]-1][b[i][1]] == 'S' ||a[b[i][0]][b[i][1]+1] == 'S' ||a[b[i][0]][b[i][1]-1] == 'S')
		{
			printf("No");
			return 0;
		}
		if(a[b[i][0]+1][b[i][1]] != 'W' && b[i][0]+1 < r)
			a[b[i][0]+1][b[i][1]] = 'D';
		if(a[b[i][0]-1][b[i][1]] != 'W' && b[i][0]-1 >= 0)
			a[b[i][0]-1][b[i][1]] = 'D';
		if(a[b[i][0]][b[i][1]+1] != 'W' && b[i][1]+1 < c)
			a[b[i][0]][b[i][1]+1] = 'D';
		if(a[b[i][0]][b[i][1]-1] != 'W' && b[i][1]+1 >= 0)
			a[b[i][0]][b[i][1]-1] = 'D';
	}
	printf("Yes\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}