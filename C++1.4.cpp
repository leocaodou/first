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
	while(max)//从个位开始相加，逐渐升高位数
	{
		int x = 0,y = 0;
		if(min > 0)//判断位数少的数是否已经全部加完
	  		x = d[min - 1] - 48;//用较小的数的从左往右第min位的ASCII码减去48即为那一位代表的数字
	  	if(s == 1)//s用于判断上一位是否相加进位，是的话s为1，让x加一后，s回归0
	  	{
	  		x++;
	  		s = 0;//s回归0
	  	}
		y = c[max - 1] + x;//让较大的数的从左往右第max位的ASCII码加入x
		if(y >= 58)//判断这一位加完了是否要进位
		{
			y = y - 10;
			s = 1;//需要进位，因此把s换为1，提醒下一位相加时要进位
		}
		c[max - 1] = y;//此时的y值的ASCII码即代表了我们那一位所需要的数，直接让较大数的从左往右第max位等上即可
		max--;//向左移一位（即更高位）继续相加
		min--;
		if(min <= 0&&s==0)
			break;//若较少位的数已经加完且不需要进位，则可以直接退出循环
	}
	if(s == 1)//如果在较多位数都已经加完，仍需要进位，说明最后数字比max多了一位
	{
		char *f = new char[strlen(c) + 2];//需要重新开辟出位数多一位的字符串来存放数字
		f[0] = '1';//由于进位，所以第一位一定是1
		for(i = 0;i <strlen(c);i++)//才开辟的空间从第二位开始都和相加之后的较多位数的数的第一位相同，之后一样
		{
			f[i+1] = c[i];
		}
		f[strlen(c) + 1] = '\0'; 
		delete [] c;
		delete [] d;//释放开辟出来的动态空间（？）
		return f;
	}
	else
	{
		delete [] d;
		return c;
	}
	delete [] c;
	delete [] d;
}
int main()
{
	char *a ="9",*b = "1";
	char *r = long_integer_addition(a,b);
	printf("%s\n",r);
	return 0;
}
