#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Person{
	char *name;
	char gender;
	int year;
	int month;
	int day;
	Person()
	{
		name = NULL;
		gender = '\0';
		year = 1990;
		month = 1;
		day = 1;
	}
	Person(const char *n,const char a,const int y,const int m,const int d)
	{
		printf("Person(const char*, char, int, int, int)\n");
		year = y;
		month = m;
		day = d;
		gender = a;
		if(n !=NULL)
		{
			name = new char[strlen(n) + 1];
			strcpy(name,n);
		}
	}
	Person(const Person& other)
	{
		printf("Person(const Person&)\n");
		year = other.year;
		month = other.month;
		day = other.day;
		gender = other.gender;
		name = NULL;
		if(other.name)
		{
			name = new char[strlen(other.name) + 1];
			strcpy(name,other.name);
		}
	}
	~Person()
	{
		delete [] name;
		printf("~Person()\n");
	}
	void Print()
	{
		printf("name:%s\n",name);
		printf("gender:%c\n",gender);
		printf("Birthday:%d-",year);
		if(month < 10)
			printf("0%d-",month);
		else
			printf("%d-",month);
		if(day < 10)
			printf("0%d",day);
		else
			printf("%d",day);
		printf("\n");
	}
	void setName(const char *n)
	{
		if(n)
		{
			name = new char[strlen(n + 1) + 1];
			strcpy(name, n);
		}
	}
	void setGender(const char a)
	{
		gender = a;
	}
	void setBirthday(const int y,const int m,const int d)
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
   getchar();
   scanf("%c", &gender);
   Person p(name, gender, year ,month, day);
   memset(name, 0, 100);
   p.Print();
   Person s (p);
   s.Print();
   s.setName("Mark");
   s.setGender('F');
   s.Print();
   p.Print();
   Person *r = new Person(s);
   r->Print();
   delete r;   
   return 0;
}
