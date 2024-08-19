/*
https://cses.fi/problemset/task/1649/
*/
#include<bits/stdc++.h>
using namespace std;
int const mx=2e5+123;
long long a[mx],t[4*mx];
void init(int id,int b,int e)
{
    if(b==e)
    {
        t[id]=a[b];
        return ;
    }
    long long mid=(b+e)>>1;
    init(id*2,b,mid);
    init(id*2+1,mid+1,e);
    t[id]=min(t[id*2],t[id*2+1]);
}
void update(long long id,long long b,long long e,long long k,long long u)
{
    if(e<k || b>k)
    {
        return;
    }
    if(b==k && e==k)
    {
        t[id]=u;
        return;
    }
    long long mid=(b+e)>>1;
    update(id*2,b,mid,k,u);
    update(id*2+1,mid+1,e,k,u);
    t[id]=min(t[id*2],t[id*2+1]);
}
long long ask(int id,int b,int e,int i,int j)
{
    if(e<i || b>j)
    {
        return INT_MAX;
    }
    if(b>=i && e<=j)
    {
        return t[id];
    }
    long long mid=(b+e)>>1;
    long long leftmin=ask(id*2,b,mid,i,j);
    long long rightmin=ask(id*2+1,mid+1,e,i,j);
    return min(leftmin,rightmin);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       long long n,q;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
       }
       init(1,1,n);//O(n*log2(n));
       while(q--)
       {
           int type;
           cin>>type;
           if(type==1)
           {
               long long k,u;
               cin>>k>>u;
               update(1,1,n,k,u);//O(log2(n));
           }
           else
           {
               int i,j;
               cin>>i>>j;//O(log2(n))
               cout<<ask(1,1,n,i,j)<<endl;
           }
       }
    }
    return 0;
}


