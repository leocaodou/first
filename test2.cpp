#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
 	double pi = 3.1415926;
	int n;
	cin>>n;
    cout<<setiosflags(ios::fixed)<<setprecision(0)<<pi<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<pi<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<pi<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<pi<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(4)<<pi<<endl;
	return 0;
}
