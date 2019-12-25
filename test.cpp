#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int* getNext(string& ps) {
    int* next = new int [ps.length()];
    next[0] = -1;

    int j = 0;

    int k = -1;

    while (j < ps.length() - 1) {
       if (k == -1 || ps[j] == ps[k])
	   {
           next[++j] = ++k;
       } 
	   else 
	   {
           k = next[k];
       }
    }
    return next;
}
int* getNext2(string& ps) {
    int* next = new int [ps.length()];
    next[0] = -1;

    int j = 0;

    int k = -1;

    while (j < ps.length() - 1) {
       if (k == -1 || ps[j] == ps[k])
	   {
           if (ps[++j] == ps[++k])
		   {
            	next[j] = next[k];
           }
		   else
		   {
            	next[j] = k;
           }
       }
	   else 
	   {
           k = next[k];
       }
    }
    return next;
}
int main()
{
	string a ="ababaaababaa";
	int* next = getNext(a);
	for(int i = 0;i < a.length();i++)
	{
		cout << next[i]<<endl                                                                                               ;
	}
	cout << endl << endl;
	next = getNext2(a);
	for(int i = 0;i < a.length();i++)
	{
		cout << next[i]<<endl                                                                                               ;
	}
}
