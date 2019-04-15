#include <iostream>
using namespace std;
int add(const int x, const int y)//专门对于整型相加的函数，传入的x与y不能修改需要加const
{
	printf("int add(const int , const int)\n");
	return x + y;
}
float add(const float x, const float y)//专门对于浮点型相加的函数
{
	printf("float add(const float , const float)\n");
	return x + y;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
    	float f1, f2;
		int a, b;
		cin >> f1 >> f2 >> a >> b;
		cout << add(f1, f2) << "\n" << add(a, b) << "\n";
     }
    return 0;
}