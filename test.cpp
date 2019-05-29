#include<iostream>
#include<cstring>
using namespace std;
class Teacher{
protected:
	string name;
	int age;
	string title;
public:
	Teacher(string n,int a,string t):name(n),age(a),title(t){}
}; 
class Student{
protected:
	string name1;
	char sex;
	float score;
public:
	Student(char s,float sc):sex(s),score(sc){}
}; 
class Graduate:public Student,public Teacher{
protected:
	int wages;
public:
Graduate(string n,int a,char s,string t,float sc,int w):Teacher(n,a,t),Student(s,sc),wages(w){}	
void show();
};
void Graduate::show(){
	cout<<"name:"<<name<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"sex:"<<sex<<endl;
	cout<<"score:"<<score<<endl;
	cout<<"title:"<<title<<endl;
	cout<<"wages:"<<wages<<endl;
}

int main()
{
Graduate grad1("Wang-li",24,'f',"assistant",89.5,2400);
grad1.show();
return 0;
}