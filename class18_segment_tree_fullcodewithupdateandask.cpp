/* 
ekhane dynamically update hbe and range er sum jigges korbe 
problem : https://cses.fi/problemset/task/1648/ 
*/
#include<bits/stdc++.h>
using namespace std;
int const mx=2e5+123;
long long t[mx*4],a[mx];
void init(long long id,long long b,long long e)
{
   if(b==e)
   {
       t[id]=a[b];
       return;
   }
   long long mid=(b+e)>>1;
   init(id*2,b,mid);
   init(id*2+1,mid+1,e);
   t[id]=t[id*2]+t[id*2+1];
}
void update(long long id,long long b,long long e,long long k,long long u)
{
    if(b>k || e<k)
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
    t[id]=t[id*2]+t[id*2+1];
}
long long ask(long long id,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return t[id];
    }
    long long mid=(b+e)>>1;
    long long left=ask(id*2,b,mid,i,j);
    long long right=ask(id*2+1,mid+1,e,i,j);
    return left+right;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long q,n;
       cin>>n>>q;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
       }
       init(1,1,n);
       while(q--)
       {
           long long x;
           cin>>x;
           if(x==1)
           {
               long long k,u;
               cin>>k>>u;
               update(1,1,n,k,u);
           }
           else
           {
               long long a,b;
               cin>>a>>b;
               cout<<ask(1,1,n,a,b)<<endl;
           }
       }
    }
    return 0;
}


