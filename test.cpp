#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k[n];
    for(int  i=0;i<n;++i)   cin>>k[i];  
    int  count=1;
    for(int  i=n-1;i>0;--i){
        if(k[i]==0) count++;
        if(k[i-1]<=k[i]-1)  k[i-1]=k[i]-1;
    }
    cout<<count<<endl;
}