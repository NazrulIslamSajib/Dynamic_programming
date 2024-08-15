/*
https://lightoj.com/problem/civil-and-evil-engineer  
ekhane 0 theke koyek ta bulding jora lagate cay enginner ra. tai minimum maximum cost ber korte cay tara,  
seta avg ber korte cay. maximum spanning tree mane weight gula ke reverse sort korlei hoy.     
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>sz;
int find_par(int u)
{
    if(par[u]==u)
    {
        return u;
    }
    return par[u]=find_par(par[u]);
}
void uni(int u,int v)
{
    if(sz[u]<sz[v]) swap(u,v);
    par[v]=par[u];
    sz[u]+=sz[v];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
    {
        int n,i;
        cin>>n;
        vector<pair<int,pair<int,int>>>edges;
        while(1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(u==0 && v==0 && w==0)
            {
                break;
            }
            else
            {
                edges.push_back({w,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        par.clear();
        sz.clear();
        for(i=0;i<=n+4;i++)
        {
            par.push_back(i);
            sz.push_back(1);
        }
        int cnt1=0,sum1=0,cnt2=0,sum2=0,sum=0;
        for(auto x:edges)
        {
            int w=x.first;
            int u=x.second.first;
            int v=x.second.second;
            u=find_par(u);
            v=find_par(v);
            if(u!=v)
            {
                uni(u,v);
                cnt1++;
                sum1+=w;
                if(cnt1==n)
                {
                    break;
                }

            }
        }
        sz.clear();
        par.clear();
        for(i=0;i<=n+4;i++)
        {
            par.push_back(i);
            sz.push_back(1);
        }
        reverse(edges.begin(),edges.end());
        for(auto x:edges)
        {
            int w=x.first;
            int u=x.second.first;
            int v=x.second.second;
            u=find_par(u);
            v=find_par(v);
            if(u!=v)
            {
                uni(u,v);
                cnt2++;
                sum2+=w;
                if(cnt2==n)
                {
                    break;
                }

            }
        }
        sum=sum1+sum2;
        if(sum%2==0)
        {
            cout<<"Case "<<tc<<": "<<sum/2<<endl;
        }
        else
        {
            cout<<"Case "<<tc<<": "<<sum<<"/2"<<endl;
        }
    }
    return 0;
}
