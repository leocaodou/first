#include <stdio.h>
int main()
{
	int n,k,s;
	scanf("%d%d",&n,&k);
	s=2+3+(n-2)*2;
	if(k<=n/2)
		s=s+(k-1)+(n-1);
	else
		s=s+(n-k)+n-1;
	printf("%d",s);
}