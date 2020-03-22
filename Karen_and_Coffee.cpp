#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
const int MAX = 200010 ;
int cnt[MAX] ;
int sum[MAX] ;
int main()
{
	int n , k , q ;
    cin >> n >> k >>q ;
    for(int i = 1 ;i<= n ;i++)
    {
        int b , e ;
        scanf("%d%d",&b,&e);
        cnt[b]++ ;
        cnt[e+1]-- ;
    }
    for(int i = 1 ; i<200010 ;i++)
    {
        cnt[i]+=cnt[i-1] ;
        if(cnt[i]>=k)
            sum[i]++ ;
        sum[i]+=sum[i-1] ;
    }
 
    while(q--)
    {
        int b ,e ;
        scanf("%d%d",&b,&e);
        printf("%d\n",sum[e]-sum[b-1]);
 
    }
    return 0 ;
}