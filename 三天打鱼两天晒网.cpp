#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
int main()
{
	struct date a;
	int n,y,r,i,s;
	printf("Enter year/month/day: ");
	scanf("%d/%d/%d",&a.year,&a.month,&a.day);
	n=(a.year-1990)*365+(a.year-1990+2)/4;
	if(a.year%400==0||(a.year%4==0&&a.year%100!=0))
	{
		for(i=1;i<a.month;i++)
		{
			if(i==1)
				y=y+31;
			if(i==2)
				y=y+29;
			if(i==3)
				y=y+31;
			if(i==4)
				y=y+30;
			if(i==5)
				y=y+31;
			if(i==6)
				y=y+30;
			if(i==7)
				y=y+31;
			if(i==8)
				y=y+31;
			if(i==9)
				y=y+30;
			if(i==10)
				y=y+31;
			if(i==11)
				y=y+30;
			if(i==12)
				y=y+31;
		}
	}
		else
		{
			for(i=1;i<a.month;i++)
			{
				if(i==1)
					y=y+31;
				if(i==2)
					y=y+28;
				if(i==3)
					y=y+31;
				if(i==4)
					y=y+30;
				if(i==5)
					y=y+31;
				if(i==6)
					y=y+30;
				if(i==7)
					y=y+31;
				if(i==8)
					y=y+31;
				if(i==9)
					y=y+30;
				if(i==10)
					y=y+31;
				if(i==11)
					y=y+30;
				if(i==12)
					y=y+31;
		}
	}
	s=n+y+a.day-(a.year-1900)/100;
		printf("Output:\n");
	if(s%5==0||s%5==4)
		printf("He was sleeping at that day.\n");
	else
		printf("He was fishing at that day.\n");
	return 0;
}
