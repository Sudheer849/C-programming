#include<iostream>
using namespace std;
long long int a[1000005],b[1000005];
int main()
{
    long long int n=1000001;
    for(int i=2; i<n; i++)
    {
        a[i]=0;
        b[i]=0;
    }
    for(int i=2; i<n; i++)
    {
        if(a[i]==0)
        {
            for(int j=i; j<n; j=j+i)
            {

                if(b[j]==0)
                {
                    b[j]=b[j]+i;
                }
                a[j]=1;
            }
        }
    }
    long long int t;
    cin>>t;
    while(t!=0)
    {
        long long int m;
        cin>>m;
        while(m!=1)
        {
            cout<<b[m]<<" ";
            m=m/b[m];
        }
        t=t-1;
    }
    return 0;
}





















