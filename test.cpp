#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char* s=new char("asdas");
    memmove(s,"ad",2);
    cout << s;
    return 0;
}
