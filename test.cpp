#include<iostream>
#include<cstring>
using namespace std;
class Person{
protected:
string name;
char sex;
public:
	Person():name(),sex('U'){}
	Person(string n,char s):name(n),sex(s){}
void setName(string n){
	name=n;
}
void setSex(char s){
	sex=s;
}
};
class Teacher:virtual public Person{
protected:
string title;
public:
	Teacher():title(){}
	Teacher(string n,char s ,string t ):Person(n,s),title(t){}
	Teacher(string t) : title(t){}
};
class Student:virtual public Person{
protected:
double score;
public:
    Student():score(0){}
	Student(string n = NULL,char s = 'U',double sc = 0):Person(n,s),score(sc){}
	Student(double sc):score(sc){}
	}; 
class Graduate:public Teacher,public Student{
public:
	Graduate(string t,double sc ,string n,char s):
	Teacher(n,s,t),Student(n,s,sc),Person(n,s){}
	Graduate(string t,double sc):
	Teacher(t),Student(sc){}
	void show(){
		cout<<"name:" <<name<<"\n";
		cout<<"sex:" <<sex<<"\n";
		cout<<"title:" <<title<<"\n";
		cout<<"score:" <<score<<"\n";
	}
};
int main()
{
	Graduate grad1("Assistance", 89.5);
	grad1.show();
	printf("\n");
	grad1.setName("Wang Li-Li");
	grad1.setSex('M');
	grad1.show();
	return 0;
}