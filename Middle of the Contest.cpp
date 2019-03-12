#include <stdio.h>
int main ()
{
	char a[6],b[6];
	int c,t,h,h1,m1;
	scanf("%s",a);
	scanf("%s",b);
	c=(b[0]-'0')*10+b[1]-a[1]-(a[0]-'0')*10;
	t=(c*60+(b[3]-'0')*10+b[4]-(a[3]-'0')*10-a[4])/2;
	h=t/60;
	h1=a[1]-48+(a[0]-'0')*10+h;
	m1=(a[3]-'0')*10+a[4]+t%60-48;
	if(m1>=60)
	{
		m1=m1-60;
		h1++;
	}
	if(h1<10&&m1<10)
		printf("0%d:0%d",h1,m1);
	if(h1<10&&m1>=10)
		printf("0%d:%d",h1,m1);
	if(h1>=10&&m1<10)
		printf("%d:0%d",h1,m1);
	if(h1>=10&&m1>=10)
		printf("%d:%d",h1,m1);
	return 0;
}