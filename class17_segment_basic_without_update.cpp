#include<bits/stdc++.h>
using namespace std;
int const mx=1e5;
int t[mx*3],a[mx];
void init(int id,int b,int e)
{
    if(b==e)
    {
        t[id]=a[b];
        return ;
    }
    int mid=(b+e)/2;
    init(id*2,b,mid);
    init(id*2+1,mid+1,e);
    t[id]=t[id*2]+t[id*2+1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
       }
       init(1,1,n);
       for(int i=1;i<=15;i++)
       {
           cout<<t[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}


