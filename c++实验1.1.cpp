#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class Person{
private: //Person类当中不希望别人直接修改成员所以设为私有
	char *name;
	char gender;
	int year;
	int month;
	int day;
public:
	Person()//无参数的构造函数，把构造的对象赋上初值
	{
		name = NULL;
		gender = '\0';
		year = 1900;
		month = 1;
		day = 1;
	}
	Person(const char *n,const char a,const int y,const int m,const int d)//带有参数的构造函数
	{
		printf("Person(const char*, char, int, int, int)\n");
		year = y;
		month = m;
		day = d;
		gender = a;
		if(n !=NULL)//判断传入的指针*n是否为空，若为空则不需要新开辟空间
		{
			name = new char[strlen(n) + 1];//动态分配一个空间来拷贝传入的字符串，strlen()函数不能放空值
			strcpy(name,n);
		}
	}
	Person(const Person& other)//拷贝构造函数
	{
		printf("Person(const Person&)\n");
		year = other.year;
		month = other.month;
		day = other.day;
		gender = other.gender;
		name = NULL;
		if(other.name)//理由同上的带有参数的构造函数，先判断需要拷贝的对象名字是否为空
		{
			name = new char[strlen(other.name) + 1];
			strcpy(name,other.name);
		}
	}
	~Person()//析构函数
	{
		delete [] name;//用于删除之前对于*name开出的动态空间，否者在某些情况中，空间会一直堆砌使程序崩溃
		printf("~Person()\n");
	}
	void Print()//这个函数用于一次性输出对象的所有信息
	{
		printf("name:%s\n",name);
		printf("gender:%c\n",gender);
		printf("Birthday:%d-%02d-%02d\n",year,month,day);
	}
	void setName(const char *n)//这个函数用于输出修改与赋予Person对象的name值
	{
		if(name)//得先判断name是否已经被赋值过，若是这要删除动态空间，以防空间堆砌
		{
			delete [] name;
			name = NULL;
		}
		if(n)//理由同的带有参数的构造函数与拷贝构造函数
		{
			name = new char[strlen(n + 1) + 1];
			strcpy(name, n);
		}
	}
	void setGender(const char a)//这个函数用于设置Person对象的性别
	{
		gender = a;
	}
	void setBirthday(const int y,const int m,const int d)//这个函数用于设置Person对象的生日
	{
		year = y;
		month = m;
		day = d;
	}
};
int main(){
   char name[100];
   int year, month, day;
   char gender;
   scanf("%s", name);
   scanf("%d%d%d", &year, &month, &day);
   getchar();//吸收上一个输入完后的回车
   scanf("%c", &gender);
   Person p(name, gender, year ,month, day);//使用带有参数的构造函数
   p.Print();
   Person *r = new Person(p);//通过动态分配的方式实例化一个Person类的对象，并使用拷贝构造函数对该初始化该对象
   r->Print();
   delete r;//清除在主函数中动态分配的空间
   return 0;
}
