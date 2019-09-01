#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int n,p,q,m,k = 0,*w,amax,y;
unsigned int SA,SB,SC;
void PUSH(int v)
{
	if( v > amax)
		amax = v;
	int *x;
	x = new int[k + 1];
	for(int i = 0;i < k;i++)
	{
		x[i] = w[i];
	}
	delete [] w;
	x[k] = v;
	w = x;
	k++;
}
void POP()
{
	int *x;
	if( k == 0)
		return;
	x = new int[k - 1];
	for(int i = 0;i < k - 1;i++)
	{
		x[i] = w[i + 1];
	}
	delete [] w;
	w = x;
	k--;
}
unsigned int rng61()
{
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA; SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}
void gen()
{
	scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
	for(int i = 1;i <=n ;i++)
	{
		if(rng61() % (p + q) < p)
			PUSH(rng61() % m + 1);
		else
			POP();

		if(i == 1 && k > 0)
		{
			y =  (*max_element(w, w + k));
		}
		else
		{
			if(k > 0)
				y = y ^ (i *  (*max_element(w, w + k)));
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		k = 0;
		amax = 0;
		gen();
		cout << "Case #" << i + 1 << ": " << y << '\n';
	}
	return 0;
}