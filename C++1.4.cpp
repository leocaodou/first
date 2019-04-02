#include <stdio.h>
#include <string.h>
char* long_integer_addition(const char *a,const char *b)
{
	int max,p,s=0,i,min;
	char *c,*d;
	if(strlen(a) > strlen(b))//判断*a与*b那个的位数多，以比较长的字符串为主来加更加方便
	{
		max = strlen(a);
		min = strlen(b);
		c = new char[strlen(a) + 1];//由于*a与*b指向常量无法改变，需要开辟动态空间来存放，才能修改
		strcpy(c,a);
		d = new char[strlen(b) + 1];
		strcpy(d,b);
	}
	else
	{
		max = strlen(b);
		min = strlen(a);
		c = new char[strlen(b) + 1];
		strcpy(c,b);
		d = new char[strlen(a) + 1];
		strcpy(d,a);
	}
	while(max)
	{
		int x = 0,y = 0;
		if(min > 0)
	  		x = d[min - 1] - 48;
	  	if(s == 1)
	  	{
	  		x++;
	  		s = 0;
	  	}
		y = c[max - 1] + x;
		if(y >= 58)
		{
			y = y - 10;
			s = 1;
		}
		c[max - 1] = y;
		max--;
		min--;
		if(min <= 0&&s==0)
			break;
	}
	if(s == 1)
	{
		char *p = new char[strlen(c) + 2];
		p[0] = '1';
		for(i = 0;i <strlen(c);i++)
		{
			p[i+1] = c[i];
		}
		return p;
	}
	else
		return c;

}
int main()
{
	char *a ="0001200000320987630",*b = "1";
	char *r = long_integer_addition(a,b);
	printf("%s\n",r);
	return 0;
}
