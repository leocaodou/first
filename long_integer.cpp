#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
class long_integer
{
private:
	stack<int> num;
	char x;
public:
	long_integer(string x)
	{
		int j = 0;
		if(x[0] == '-')
		{
			this->x = '-';
			j = 1;
		}
		else
			this->x = '+';
		for(int i = j;i < x.size();i++)
		{
			num.push(x[i] - 48);
		}
	}
	bool empty()
	{
		return num.empty();
	}
	int get()
	{
		return num.top();
	}
	void pop()
	{
		num.pop();
	}
};
void addition(long_integer a,long_integer b)
{
	int k = 0;
	stack<int> c;
	while(!a.empty() || !b.empty() || k == 1)
	{
		int x,y;
		if(!a.empty())
		{
			x = a.get();
			a.pop();
		}
		else
			x = 0;
		if(!b.empty())
		{
			y = b.get();
			b.pop();
		}
		else
			y = 0;
		int z = x + y + k;
		if(z > 10)
		{
			c.push(z - 10);
			k = 1;
		}
		else
		{
			c.push(z);
			k = 0;
		}
	}
	while(!c.empty())
	{
		cout << c.top();
		c.pop();
	}
}
void subtraction(long_integer a,long_integer b)
{
	int k = 0;
	stack<int> c;
	while(!a.empty() && !b.empty() && k == 0)
	{
		int x,y;
		if(!a.empty())
		{
			x = a.get();
			a.pop();
		}
		else
			x = 0;
		if(!b.empty())
		{
			y = b.get();
			b.pop();
		}
		else
			y = 0;
		int z = x - y + k;
		if(z < 0)
		{
			c.push(0-z);
			k = -1;
		}
		else
		{
			c.push(z);
			k = 0;
		}
	}
	while(!c.empty())
	{
		cout << c.top();
		c.pop();
	}
}
bool bigger(string a,string b)
{
	int i = 0,j = 0;
	if(a[0] == '-')
		i = 1;
	if(b[0] == '-')
		j = 1;
	if(a.size() - i > b.size() - j)
		return true;
	else if(a.size() - i < b.size() - j)
		return false;
	else
	{
		for(int k = 0;k < (a.size() - i);k++)
		{
			if(a[k + i] > b[i + i])
				return true;
			if(a[k + i] < b[i + i])
				return false;
		}
		return true;
	}
}
int main()
{
	string a,b;
	int k = 0;
	char c;
	cin >> a >> c >> b;
	if(a[0] == '-')
		k++;
	if(c == '-')
		k++;
	if(b[0] == '-')
		k++;
	long_integer x(a);
	long_integer y(b);
	if(k % 2 == 0)
	{
		if(a[0] == '-')
			cout << '-';
		addition(x,y);
	}
	else
	{
		if(a[0] == '-' && bigger(a,b))
			cout << '-';
		else if(!bigger(a,b))
			cout << '-';
		subtraction(x,y);
	}
	
}
