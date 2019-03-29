#include <stdio.h>
#include <math.h>
int main()
{
	long long n,s=9,x;
	int k=0,y=0,i;
	scanf("%lld",&n);
	while(1)
	{
		int c = n/pow(10,k);
		if(c==0)
			break;
		k++;
	}
	for(i=2;i<k;i++)
		s = s*10+9;
	if(k>=2)
		x=n-s;
	else
		x=n;
	while(x)
	{
		y=y+x%10;
		x=x/10;
	}
	y=y+9*(k-1);
	printf("%d",y);
	return 0;
}
