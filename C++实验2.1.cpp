#include <iostream>
using namespace std;
int add(const int x, const int y)
{
	printf("int add(const int , const int)\n");
	return x + y;
}
float add(const float x, const float y)
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