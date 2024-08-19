/*
https://cses.fi/problemset/task/1651/ 
lazy propagation 
ekahne jei range ta increase korbo seta jeta jodin kono range er modde pore seta te update kore prog[id] 
niche jabo na mane root node e jabo na . 

*/
#include<bits/stdc++.h>
using namespace std;
int const mx=2e5+123;
long long a[mx],prog[4*mx];
bool vis[mx*4];
void init(int id,int b,int e) /// O(n*log2(n))
{
    if(b==e)
    {
        prog[id]=a[b];
        return ;
    }
    long long mid=(b+e)>>1;
    init(id*2,b,mid);
    init(id*2+1,mid+1,e);

}
void update(int id,int b,int e,int i,int j,int v) //O(log2(n))
{
    if(e<i || j<b)
    {
        return;
    }
    if(b>=i && e<=j) /// majkhane porlei seta prog kortechi.
    {
        prog[id]+=v;
        vis[id]=1;
        return;
    }
    long long mid=(b+e)>>1;
    update(id*2,b,mid,i,j,v);
    update(id*2+1,mid+1,e,i,j,v);

}
void shift(int id) //// er modde kono value thakle seta niche diye dibe //O(log2(n))
{
    prog[id*2]+=prog[id];
    prog[id*2+1]+=prog[id];
    vis[id*2]=1;
    vis[id*2+1]=1;
    prog[id]=0;
    vis[id]=0;
}
long long ask(int id,int b,int e ,int k) ///O(log2(n))
{
    if(e<k || b>k)
    {
        return 0;
    }
    if(e==k && b==k)
    {
        return prog[id];
    }
    if(vis[id]==1)
    {
        shift(id);
    }
    long long mid=(b+e)>>1;
    long long leftmin=ask(id*2,b,mid,k);
    long long rightmin=ask(id*2+1,mid+1,e,k);
    return (leftmin+rightmin); ///ekhane 1 zero arek ta onno value asbe
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
       init(1,1,n);
       while(q--)
       {
              int type;
              cin>>type;
              if(type==1)
              {
                  int a,b,v;
                  cin>>a>>b>>v;
                  update(1,1,n,a,b,v);
              }
              else
              {
                  long long k;
                  cin>>k;
                  cout<<ask(1,1,n,k)<<endl;
              }
       }
    }
    return 0;
}


