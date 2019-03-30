#include <stdio.h>
#include<string.h>
#include<stdlib.h>
 class Person {
   public:
    Person()  //第一个构造函数 
    {  
        gender = '\0';
		name = NULL;
		year = 1990;
        month = 1;
        day = 1;
	}
    Person(char *n, char c, int y, int m, int d)  //赋值 
	{
	printf("Person(const char*, char, int, int, int)\n");
	    gender=c;
			if(n)
		{
		name = new char[strlen(n+1)+1];
		strcpy(name,n);
		}	
		year = y;
        month = m;
        day = d;
	}
	Person(const Person& other)    
	{    //拷贝构造函数 
		printf("Person(const Person&)\n");
		gender = other.gender;
		if(other.name)
		{
			name = new char[strlen(other.name+1)+1];
			strcpy(name,other.name);
		}
		year = other.year;
        month = other.month;
        day = other.day;
	}
    ~Person()    //析构函数 
    {       
  	printf("~Stu\n");
  	delete [] name;
    } 
	void Print(){      //输出 
    printf("name:%s\ngender:%c\nBirthday:%d-%d-%d\n",name,gender,year,month, day);
    } 
	void setName(const char *n)     //复制
	{
		if(n)
		{
		name = new char[strlen(n+1)+1];
		strcpy(name,n);
		}	
	}
	void setGender(const char c)   //复制 
	{
		gender = c;
	}
	void setBirthday(const int a, const int b, const int c)  //复制 
	{
	year = a;
    month = b;
    day = c;	
	}
    private:
     char* name;
     char gender;
     int year;
     int month;
     int day;
 } ; 
int main(){
   char name[100];
   int year, month, day;
   char gender;
   scanf("%s", name);      
   scanf("%d %d %d", &year, &month, &day);
   
   scanf(" %c", &gender);       
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