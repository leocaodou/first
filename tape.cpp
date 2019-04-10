#include<stdio.h>
class  A  {
 	int*  a;
 	virtual  void  foo(){  }
 	void  foo1(int  a){  }
};
int main()
{
	printf("%p",sizeof(A));
}