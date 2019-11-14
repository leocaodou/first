#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stack>
using namespace std;
int main()
{
	int n;
    cin >> n;
    int u[n] = {0},v[n] = {0},c[n + 1] = {0},cnt[n + 1] = {0},sum = 0;
    for(int i = 1; i < n; i++)
        cin >> u[i] >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i < n; i++)
    {
        if(c[u[i]] != c[v[i]])
        {
            sum++;
            cnt[u[i]]++;
            cnt[v[i]]++;
        }
 
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == sum)
        {
            cout << "YES" << endl << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}