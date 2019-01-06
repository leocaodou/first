#include <stdio.h>
int main()
{
	int n,i,t,j,s=0,p=0,z,x;
	printf("Please input n: ");
	scanf("%d",&n);
	if(n<=1)
	{
		printf("Output:\nInput error!\n");
		return 0;
	}
	printf("Output:\nThere are following friendly-numbers:\n");
	for(i=1;i<n;i++)
	{
		s=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				s=s+j;		
		}
		if(s<=i)
			continue;
		z=s;
		p=0;
		for(t=1;t<z;t++)
		{
			if(z%t==0)
				p=p+t;
			if(p>i)
				break;
		}
		if(s==z&&i==p)
		{
			printf("%d--%d\n",i,z);
		} 
	}
	return 0;
}
