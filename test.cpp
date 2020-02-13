#include<iostream>
#include<algorithm>
using namespace std;
int beg[5005],en[5005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>beg[i]>>en[i];
        int st=1;
        for(int i=0;i<n;i++)
        {
            if(en[i]>=st)
            {
                if(beg[i]>st)
                {
                    cout<<beg[i]<<' ';
                    st=beg[i];
                }
                else
                {
                    cout<<st<<' ';
                }
                st++;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}